;aerodromo.clp

(deffunction tiempoestimado1 (?vel ?dist)
    (return (/ ?dist ?vel))
)

(deffunction tiempoestimado2 (?vel ?dist)
    (bind ?tiempo (/ ?dist ?vel))
    (bind ?tiemponormal (* ?tiempo 60))
    (bind ?horas (div ?tiemponormal 60))
    (bind ?minutos (- ?tiemponormal (* ?horas 60)))

    (println "Tiempo: horas " ?horas " minutos " ?minutos)
)

(deftemplate aeronave
    (slot idAeronave)
    (slot compania) 
    (slot velocidad (type FLOAT))
    (slot peticion (allowed-values Ninguna Despegue Aterrizaje Emergencia Intecerptacion Informacion Rumbo))
    (slot estado (allowed-values enTierra Ascenso Crucero Descenso)(default enTierra))
)

(deftemplate aerodromo
    (slot idAerodromo)
    (slot ciudad)
    (slot radar (allowed-values ON OFF))
    (slot radioVisibilidad (type FLOAT))
    (slot velocidadViento (type FLOAT))
)

(deftemplate piloto
    (slot idPiloto)
    (slot estadoAccion (allowed-values OK SOS Ejecutando Stand-by)(default Stand-by))
)

(deftemplate vuelo
    (slot idVuelo)
    (slot idAeronave)
    (slot idPiloto)
    (slot aerodromoOrigen)
    (slot aerodromoDestino)
    (slot distancia)
    (slot velocidadDespegue (type FLOAT)(default 240.0))
    (slot velocidadEstandar (type FLOAT)(default 700.0))
)

(defrule Despegar
    ?av <- (aeronave (idAeronave ?idav)(compania ?comp)(peticion Despegue)(estado enTierra))
    ?p <- (piloto (idPiloto ?idpi)(estadoAccion OK))
    (vuelo (idVuelo ?idvu)(idAeronave ?idav)(idPiloto ?idpi)(aerodromoOrigen ?ado)(aerodromoDestino ?add)(velocidadDespegue ?vd))
    (aerodromo (idAerodromo ?ado)(ciudad ?ciudad)(radar ON)(radioVisibilidad ?rv)(velocidadViento ?vv))
    (aerodromo (idAerodromo ?add)(ciudad ?ciudadd))
    (test (> ?rv 5))
    (test (< ?vv 75))
    =>
    (println "El vuelo " ?idvu " de la compania " ?comp " va a realizar la accion despegue desde el aerodromo " ?ado " de " ?ciudad " con destino " ?ciudadd)
    (modify ?p (estadoAccion Ejecutando))
    (modify ?av (peticion Ninguna)(estado Ascenso)(velocidad ?vd))
)

(defrule Excepcion
    ?av <- (aeronave (idAeronave ?idav)(peticion Despegue))
    (vuelo (idVuelo ?idvu)(idAeronave ?idav) (idPiloto null))
    =>
    (println "El vuelo " ?idvu " no posee ningun piloto registrado")
    (modify ?av (peticion Emergencia))
)

(defrule Crucero
    ?av <- (aeronave (idAeronave ?idav)(compania ?comp)(estado Ascenso))
    ?pi <- (piloto (idPiloto ?idpi)(estadoAccion Ejecutando))
    (vuelo (idVuelo ?idvu)(idAeronave ?idav)(idPiloto ?idpi)(distancia ?dis)(velocidadEstandar ?vc))
    =>
    (bind ?tiempo (tiempoestimado1 ?vc ?dis))
    (println "El vuelo " ?idvu " ha entrado en crucero, tiene un tiempo estimado de llegada de " ?tiempo " horas")
    (modify ?av (velocidad ?vc)(estado Crucero))
    (modify ?pi (estadoAccion Stand-by))
)