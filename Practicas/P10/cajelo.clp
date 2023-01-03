;Variables Globales

(defglobal ?*YEAR* = 2022)

;Plantillas

(deffunction Dec (?num)
    (- ?num 1)
    ;o tambien
    ;(bind ?res (- ?num 1))
    ;(return ?res)
)

(deftemplate Usuario 
    (field DNI)
    (field Pin)
    (field Dinero)
)

(deftemplate Tarjeta
    (field Pin)
    (field DNI)
    (field Intentos (default 3))
    (field Limite1 (default 300))
    (field Limite2 (default 500))
    (field Year (default 2027))
    (field Validada (allowed-values Si No)(default No))
)

(deftemplate Cuenta
    (field DNI)
    (field Saldo)
    (field Estado (allowed-values EnPantalla DineroEntregado Inicial SuperaLimite SinSaldo) (default Inicial))
)

;Hechos iniciales

(deffacts iniciales
    (Tarjeta (DNI 1234)(Pin 1212)(Intentos 3)(Limite 500)(Year 2021))
    (Cuenta (DNI 1234)(Saldo 5000)(Estado Inicial))
)

(defrule SuperaIntentos
    (declare (salience 1)) ; prioridad de 1 (a mas numero, mas prioridad)
    (Usuario (DNI ?dni))
    (Tarjeta (DNI ?dni) (Intentos 0))
    =>
    (println "Se ha superado el numero de intentos")
)

(defrule PinInvalido
    ?u <- (Usuario (DNI ?dni)(Pin ?pin1))
    ?t <- (Tarjeta (DNI ?dni)(Pin ?pin2)(Intentos ?intentos))
    (test  (neq ?pin1 ?pin2))
    (test  (> ?intentos 0))
    =>
    (modify ?t (Intentos (Dec ?intentos)))
    (retract ?u) ;retiro el usuario 
    (println "Pin invalido")
)


(defrule Validar
    ?u <- (Usuario (DNI ?dni)(Pin ?pin1))
    ?t <- (Tarjeta (DNI ?dni)(Pin ?pin2)(Intentos ?intentos)(Year ?year)(Validada No))
    (test  (eq ?pin1 ?pin2))
    (test  (> ?intentos 0))
    (test  (>= ?year ?*YEAR*))

    =>
    (modify ?t (Validada Si))
    (println "Tarjeta validadad")
)

(defrule Muestra_Saldo 
    (Tarjeta (DNI ?dni)(Validada Si))
    ?c <- (Cuenta (DNI ?dni)(Saldo ?s)(Estado ~EnPantalla))
    =>
    (modify ?c (Estado EnPantalla))
    (println "Saldo: "?s)
)

(defrule Saldo_NoSuficiente
    (Tarjeta (DNI ?dni)(Validada Si)(Limite1 ?l1)(Limite2 ?l2))
    ?u <- (Usuario (DNI ?dni)(Dinero ?d))
    (Cuenta (DNI ?dni)(Saldo ?s))
    (test (> ?d ?s))
    (test (<= ?d ?l1))
    (test (<= ?d ?l2))
    =>
    (println "ERROR, el saldo no es suficiente")
    (retract ?u)
)

(defrule Comprueba_Limite1
    (Tarjeta (DNI ?dni)(Validada Si)(Limite1 ?l1))
    ?u <- (Usuario (DNI ?dni)(Dinero ?d))
    (test (>= ?d ?l1))
    =>
    (println "ERROR, el dinero supera el limite1")
    (retract ?u)
)

(defrule Comprueba_Limite2
    (Tarjeta (DNI ?dni)(Validada Si)(Limite2 ?l2))
    ?u <- (Usuario (DNI ?dni)(Dinero ?d))
    (test (>= ?d ?l1))
    =>
    (println "ERROR, el dinero supera el limite2")
    (retract ?u)
)

(defrule Entrega_Dinero
    (Tarjeta (DNI ?dni)(Validada Si)(Limite1 ?l1)(Limite2 ?l2))
    ?u <- (Usuario (DNI ?dni)(Dinero ?d))
    ?c <- (Cuenta (DNI ?dni)(Saldo ?s))
    (test (<= ?d ?s))
    (test (<= ?d ?l1))
    (test (<= ?d ?l2))
    =>
    (bind ?total ((- ?s ?d)))
    (println "Saldo: "?total)
    (modify ?c (Saldo ?total))
    (retract ?u)
)

