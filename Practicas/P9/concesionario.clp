;concesionario.clp start

; <--------------------------PLANTILLAS-------------------------->

(deftemplate Modelo
    (slot NombreModelo)
    (slot Precio (type INTEGER))
    (slot Maletero (allowed-values pequeno mediano grande))
    (slot NumCaballos (type INTEGER))
    (slot Abs (allowed-values Si No))
    (slot Consumo)
)

(deftemplate formulario
    (slot FPrecio (type INTEGER)(default 13000))
    (slot FMaletero (allowed-values pequeno mediano grande)(default grande))
    (slot FNumCaballos (type INTEGER)(default 80))
    (slot FAbs (allowed-values Si No)(default Si))
    (slot FConsumo(default 8.0))
)

; ^--------------------------PLANTILLAS--------------------------^

(deffacts Iniciales
    (Modelo
        (NombreModelo Modelo1)
        (Precio 12000)
        (Maletero grande)
        (NumCaballos 81)
        (Abs Si)
        (Consumo 4.7)
    )
    (Modelo
        (NombreModelo Modelo2)
        (Precio 12500)
        (Maletero pequeno)
        (NumCaballos 80)
        (Abs Si)
        (Consumo 4.9)
    )
    (Modelo
        (NombreModelo Modelo3)
        (Precio 13000)
        (Maletero mediano)
        (NumCaballos 100)
        (Abs Si)
        (Consumo 7.8)
    )
    (Modelo
        (NombreModelo Modelo4)
        (Precio 14000)
        (Maletero grande)
        (NumCaballos 125)
        (Abs Si)
        (Consumo 6.0)
    )
    (Modelo
        (NombreModelo Modelo5)
        (Precio 15000)
        (Maletero pequeno)
        (NumCaballos 147)
        (Abs Si)
        (Consumo 8.5)
    )
    (formulario
        (FPrecio 15000)
    )
)

; ^--------------------------HECHOS--------------------------^

; <--------------------------REGLAS-------------------------->

(defrule Recomendacion
    (Modelo (NombreModelo ?nom)(Precio ?p1)(Maletero ?m)(NumCaballos ?n1)(Abs ?a)(Consumo ?c1))
    (formulario (FPrecio ?p2)(FMaletero ?m)(FNumCaballos ?n2)(FAbs ?a)(FConsumo ?c2))
    (test (<= ?p1 ?p2))
    (test (>= ?n1 ?n2))
    (test (<= ?c1 ?c2))
=>
    (assert(Recomendacion ?nom))
);; Recomendacion