;animales.clp begin


; Hechos indicados
(deffacts animales
    (Tiene Robi Pelo)
    (Tiene Susi Plumas)
    (Color Robi Leonado)
    (Rayas Robi Negras)
    (Color Susi Blanco)
    (Vuela Susi Si)
    (Vuela Robi No)
    (Come Robi Carne)
    (Come Susi Pescado)
    (EsPadre Robi RobiJr)
)

(defrule R1
    (Tiene ?name Pelo)
    =>
    (assert (Categoria ?name Mamifero))
)

(defrule R3
    (Tiene ?name Plumas)
    =>
    (assert (Categoria ?name Ave))
)

(defrule R5
    (Come ?name Carne)
    =>
    (assert (CatComida ?name Carnivoro))
)


(defrule R10
    (Categoria ?name Mamifero)
    (CatComida ?name Carnivoro)
    (Color ?name Leonado)
    (Rayas ?name Negras)
    =>
    (assert (Especie ?name Tigre))
)

(defrule R16
    (EsPadre ?padre ?hijo)
    (Especie ?padre ?especie)
    =>
    (assert (Especie ?hijo ?especie))


)
;animales.clp end