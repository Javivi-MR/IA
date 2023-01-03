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
    (field Limite (default 300))
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