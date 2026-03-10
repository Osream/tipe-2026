(*
    Module pour transformer un ficher un en une liste de mots.
*)

(*
Complexité: O(n) où n est le nombre de mots dans le fichier.
Pre-condition: Le string passé en argument est un chemin valide vers un fichier texte.
Post-condition: Retourne une liste de mots extraits du fichier.
*)
val file_to_list : string -> string list

(*
Complexité : O(n) où n est le nombre de mots dans la liste.
Pre-condition : La liste de mots passée en argument est non vide.
Post-condition : Écrit les mots de la liste dans le fichier spécifié, un mot par ligne.
*)
val list_to_file : string list -> string -> unit
(*Cette fonction est a modifié pour qu'elle produise un code lisible*)