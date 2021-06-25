
all:
	@dune build @all

clean:
	@dune clean

watch:
	@dune build @all -w

.PHONY: test
test:
	dune exec --force src/Encoding.exe
	dune exec --force generic/GenericDecoders.exe

