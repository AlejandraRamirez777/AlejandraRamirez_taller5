caos.png: datos_caos.txt
	python caos.py

datos_caos.txt: caos.x
	./caos.x
	./caos.x > datos_caos.txt

caos.x : caos.cpp
	g++ caos.cpp -o ./caos.x
	./caos.x > datos_caos.txt
