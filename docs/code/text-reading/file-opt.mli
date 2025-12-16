(*
    Module pour transformer un ficher un en une liste de mots.
*)

(*
Complexité: O(n) où n est le nombre de mots dans le fichier.
Pre-condition: Le string passé en argument est un chemin valide vers un fichier texte.
Post-condition: Retourne une liste de mots extraits du fichier.
*)
val file_to_list : string -> string list