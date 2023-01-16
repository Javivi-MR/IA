(deffunction Reposicion (?stockcafe ?stockalma ?max)
    (if(< (+ ?stockcafe ?stockalma) ?max) then
        (return ?stockalma)
    else
        (return (- ?max ?stockcafe)))
)



(deftemplate personal
    (slot dni (type INTEGER))
    (slot nombre)
    (slot turno (allowed-values mañana tarde ambos))
    (slot total_ventas)
    (slot encargado (allowed-values SI NO))
)

(deftemplate producto
    (slot id (type INTEGER))
    (slot nombre)
    (slot stock_cafe)
    (slot stock_alma)
    (slot precio)
    (slot maximo (default 30))
)

(deftemplate venta
    (slot dni_persona)
    (slot id_producto)
    (slot unidades)
    (slot pago (allowed-values tarjeta efectivo bono))
)

;1.AsignarVenta. Esta regla refleja el pedido de un producto realizado por un cliente a
;un camarero a través del hecho ventas, siempre y cuando haya stock suficiente en
;cafetería. Se debe incrementar el acumulador de ventas del personal que atiende y
;decrementar el número de unidades existentes de ese producto de cafetería. El
;sistema imprimirá un mensaje con el siguiente formato (X es el nombre de la persona
;encargada de la venta, Y la cantidad vendida Z el nombre del producto E es el coste
;del pedido y P el método de pago):= “X: Y unidades de Z, E euros pagados con P
(defrule AsignarVenta
    ?perso <- (personal (dni ?idpersona)(nombre ?nombrepersona)(total_ventas ?tv))
    ?prod <- (producto(id ?idprod)(nombre ?nombreprod)(stock_cafe ?stock)(precio ?precio))
    ?venta <- (venta (dni_persona ?idpersona)(id_producto ?idprod)(unidades ?uds)(pago ?pago))
    (test (> ?stock ?uds))
    =>
    (bind ?total (* ?precio ?uds))
    (println ?nombrepersona ": " ?uds " unideades de " ?nombreprod ", " ?total " euros pagados con " ?pago)
    (modify ?perso (total_ventas (+ ?tv 1)))
    (modify ?prod (stock_cafe (- ?stock ?uds)))
    (retract ?venta)
)


(defrule ReponerStock
    ?prod <- (producto (stock_cafe ?stockcafe)(stock_alma ?stockalma)(maximo ?max))
    (test (< ?stockcafe 10))
    =>
    (bind ?areponer (Reposicion ?stockcafe ?stockalma ?max))
    (modify ?prod (stock_cafe (+ ?stockcafe ?areponer)) (stock_alma (- ?stockalma ?areponer)))
)