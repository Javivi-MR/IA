;supermercado.clp
(deffunction siguientePasillo(?pa)
    (if (< ?pa 12) then 
        (bind ?aux (+ ?pa 1))
    else
        (bind ?aux 1)
    )
    (return ?aux)
)

(deftemplate Producto
    (slot id)
    (slot nombre)
    (slot pasillo (type INTEGER)(allowed-values 1 2 3 4 5 6 7 8 9 10 11 12))
    (slot stock (type INTEGER))
    (slot precio (type FLOAT))
)

(deftemplate Pedido
    (slot idcliente)
    (slot idproducto)
    (slot unidades (type INTEGER))
)

(deftemplate Carro
    (slot idcliente)
    (slot articuloscomprados (type INTEGER))
    (slot total (type FLOAT))
    (slot pasilloact (type INTEGER)(allowed-values 1 2 3 4 5 6 7 8 9 10 11 12))
)

(defrule AsignarCarro
    ?nc <- (nuevo_cliente ?idc)
    (not (Carro (idcliente ?idc)))
    =>
    (assert(Carro (idcliente ?idc)(articuloscomprados 0)(total 0.0)(pasilloact 1)))
    (retract ?nc)
)

(defrule MoverCarro
    ?c <- (Carro (idcliente ?idc)(pasilloact ?pa))
    (Producto (id ?idp)(pasillo ?p))
    (Pedido (idcliente ?idc)(idproducto ?idp))
    (test (neq ?p ?pa))
    =>
    (modify ?c (pasilloact (siguientePasillo ?pa)))
)

(defrule Comprar
    ?c <- (Carro (idcliente ?idc)(articuloscomprados ?ac)(total ?total)(pasilloact ?p))
    ?prod <- (Producto (id ?idp)(pasillo ?p)(stock ?stock)(precio ?price))
    ?ped <-(Pedido (idcliente ?idc)(idproducto ?idp)(unidades ?uds))
    (test (<= ?uds ?stock))
    =>
    (bind ?compra (* ?price ?uds))
    (modify ?prod (stock (- ?stock ?uds)))
    (modify ?c (articuloscomprados (+ ?ac 1))(total (+ ?total ?compra)))
    (retract ?ped)
)

(defrule ExistenciasInsuficientes
    (Carro (idcliente ?idc)(articuloscomprados ?ac)(total ?total)(pasilloact ?p))
    (Producto (id ?idp)(pasillo ?p)(stock ?stock)(precio ?price))
    ?ped <-(Pedido (idcliente ?idc)(idproducto ?idp)(unidades ?uds))
    (test (> ?uds ?stock))
    =>
    (println "No hay suficiente stock :(")
    (retract ?ped)
)