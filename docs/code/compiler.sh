cd parser

ocamlc -o parser.cmi parser.mli 
ocamlc -o parser.cmo parser.ml
mv parser.cmo ../comp-folder/
mv parser.cmi ../comp-folder/

cd ..

cd comp-folder

ocamlc -o ../a.out -c parser.cmo recursive-transformer.ml

cd ..