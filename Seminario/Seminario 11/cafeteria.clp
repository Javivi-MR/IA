(deffunction Reposicion(?scaf ?salm ?max)
    (bind ?aux (- ?max ?scaf))
    (if(<= ?aux ?alm) then
        (return ?aux)
    else
        (return ?salm)
    )
)


(deftemplate Personal
    (slot DNI)
    (slot Nombre)
    (slot Turno (allowed-values manana tarde ambos))ç
    (slot Ventas)
    (slot Encargado (allowed-values si no))
)

(deftemplate Producto
    (slot ID)
    (slot Nombre)
    (slot Stock_act (type INTEGER))
    (slot Stock_alm (type INTEGER))
    (slot Precio (type FLOAT))
    (slot Max (default 30))
)

(deftemplate Venta
    (slot ID_Persona)
    (slot ID_Producto)
    (slot Ud (type INTEGER))
    (slot MetodoPago (allowed-values bono tarjeta efectivo))
)

(defrule AsignarVenta
    ?pers <- (Personal (DNI ?dni)(Ventas ?ventas)(Nombre ?nom))
    ?prod <- (Producto (ID ?id)(Stock_act ?sa))(Precio ?p)
    ?vent <-(Venta (ID_Persona ?dni)(ID_Producto ?id)(Ud ?ud))
    (test (>= ?sa ?ud))
    =>
    (bind ?vnuevas (+ ?ventas (* ?ud ?precio)))
    (modify ?pers (Ventas ?vnueva))
    (modify ?prod (Stock_act (- ?sa ?ud)))
    (retract ?vent)
)

(defrule Reponer
    ?prod <- (Producto (Stock_act ?sa)(Stock_alm ?sal)(Max ?m))
    (test (< ?sa 10))
    (test (> ?sal 0))
    => 
    (bind ?aux (Reposicion ?sa ?sal ?m))
    (modify ?prod (Stock_act (+ ?sa ?aux)(Stock_act (- ?sal ?aux))))

    
)