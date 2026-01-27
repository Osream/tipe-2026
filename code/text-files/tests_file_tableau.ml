open File_tableau


let tests_creer () =
    let f = creer () in
    assert (est_vide f)


let tests_est_vide () =
    let f = creer () in
    assert (est_vide f) ;
    enfiler 4.1 f ;
    assert(not (est_vide f))


let tests_enfiler () =
    let f = creer () in
    enfiler 4 f ;
    assert(not (est_vide f)) ;
    enfiler 2 f ;
    assert(defiler f = 4)


let tests_defiler () =
    let f = creer () in
    (try
        let _ = defiler f in failwith "pas d'assertions dans la fonction defiler"
    with
        | Assert_failure _ -> assert(true)
        | _ -> assert(false)
    ) ;
    enfiler 1 f ;
    enfiler 2 f ;
    assert(defiler f = 1) ;
    assert(defiler f = 2) ;
    assert(est_vide f)


let _ = tests_creer () ;
        tests_est_vide () ;
        tests_enfiler () ;
        tests_defiler ()

