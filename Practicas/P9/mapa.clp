;mapa.clp start
;Trabajamos con el siguiente mapa:
;   ABC
;   DEF
;   GHI

; <--------------------------PLANTILLAS-------------------------->

; No necesario ya que las ciudades solo tendrian un atributo (el nombre)

; ^--------------------------PLANTILLAS--------------------------^

; <--------------------------HECHOS-------------------------->
(deffacts Iniciales
    (Ubicacion A Norte D)
    (Ubicacion A Oeste B)
    (Ubicacion B Norte E)
    (Ubicacion B Oeste C)
    (Ubicacion C Norte F)
    (Ubicacion D Norte G)
    (Ubicacion D Oeste E)
    (Ubicacion E Norte H)
    (Ubicacion E Oeste F)
    (Ubicacion F Norte I)
    (Ubicacion G Oeste H)
    (Ubicacion H Oeste I)
)

; ^--------------------------HECHOS--------------------------^

; <--------------------------REGLAS-------------------------->

(defrule EstaAlSur
    (Ubicacion ?a Norte ?b)
    =>
    (assert(Ubicacion ?b Sur ?a))
);; EstaAlSur

(defrule EstaAlEste
    (Ubicacion ?a Oeste ?b)
    =>
    (assert(Ubicacion ?b Este ?a))
);; EstaAlSur

(defrule Transividad
    (Ubicacion ?a ?e ?b)
    (Ubicacion ?b ?e ?c)
    =>
    (assert(Ubicacion ?a ?e ?c))
);; Transividad

(defrule EstaAlNoresteSuroreste
    (Ubicacion ?a Norte ?b)
    (Ubicacion ?b Este ?c)
    =>
    (assert(Ubicacion ?c Noreste ?a))
    (assert(Ubicacion ?a Suroeste ?c))
);; EstaAlNoreste

(defrule EstaAlNoroesteSureste
    (Ubicacion ?a Norte ?b)
    (Ubicacion ?b Oeste ?c)
    =>
    (assert(Ubicacion ?c Noroeste ?a))
    (assert(Ubicacion ?a Sureste ?c))
);; EstaAlNoreste

(defrule DecirUbicacion
?f1 <-(situacion ?x ?y)
(Ubicacion ?x ?u ?y)
=>
(printout t ?x " esta al " ?u " de " ?y crlf)
(retract ?f1)
);; DecirUbicacion

;mapa.clp end