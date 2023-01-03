;MapaConcesionario.clp start

; <--------------------------PLANTILLAS-------------------------->

(deftemplate persona
    (multislot nombre) ;para almacenar nombre y apellidos 
    (slot dni (type INTEGER))
    (slot profesion (default estudiante))
    (slot nacionalidad (allowed-values Es Fr Po Al In It))
);persona

(deftemplate intelectual_europeo
    (multislot nombre)
    (slot dni)
    (slot idioma)
    (slot nacionalidad)
);intelectual

; ^--------------------------PLANTILLAS--------------------------^


; <--------------------------HECHOS-------------------------->

(deffacts iniciales
    ;; con hechos estructurados
    (persona 
        (nombre Mario Cantero Cansino)
        (dni 122333)
        (profesion escritor)
        (nacionalidad Es)
    )
    (persona 
        (nombre Juana Bodega Gallego) 
        (dni 3334444)
    )
    ;; con hechos no estructurados
    (ciudad Gertrudis Cadiz)
    (ciudad Filoberto Sevilla)
);;iniciales 

; ^--------------------------HECHOS--------------------------^