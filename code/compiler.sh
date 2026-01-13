cd text-reading/ &&

ocamlopt -c file.mli &&
ocamlopt -c file.ml -o ../object-files-dir/file.o &&
cp file.cmi ../test-dir/ &&

cd .. &&

cd types/ &&

ocamlopt -c token.mli &&
ocamlopt -c token.ml -o ../object-files-dir/token.o &&
cp token.cmi ../lexer/ &&

cd ..