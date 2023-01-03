;comecocos.clp

;BASE DE HECHOS

(deftemplate Comecocos
    (slot posX (default 1))
    (slot posY (default 1))
    (slot contador (default 0))
    (slot vida (default 3))
);Comecocos

(deftemplate Fantasma
    (slot posX); no definimos ningun valor inicial
    (slot posY); no definimos ningun valor inicial
);Fantasma

(deftemplate Fruta
    (slot posX)
    (slot posY)
);Fruta


(deffacts iniciales
    (Comecocos)
    (Fantasma
        (posX 1)
        (posY 2)
    )
    (Fantasma
        (posX 5)
        (posY 3)
    )
    (Fantasma
        (posX 1)
        (posY 7)
    )
    (Fruta
        (posX 3)
        (posY 1)
    )
    (Fruta
        (posX 3)
        (posY 3)
    )
    (Fruta
        (posX 3)
        (posY 5)
    )
)

;FIN BASE DE HECHOS

;REGLAS

(defrule Comer
    ?fc <- (Comecocos (posX ?x1) (posY ?y1) (contador ?c))
    ?ff <- (Fruta (posX ?x2) (posY ?y2))   ;tambien se puede pone ?x y ?y en ambos y quitar el test
    (test (= ?x1 ?x2))
    (test (= ?y1 ?y2))
    =>
    (modify ?fc (contador (+ ?c 1)))
    (retract ?ff)
)

(defrule Ganar
    (Comecocos (contador 10))
    ;o (Comecocos (contador ?c)) (test (>= ?c 10))
    =>
    (printout t "Has ganado" crlf)
    (halt)
);