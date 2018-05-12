cuerda.gif : datos_cuerda.txt
	python animacion.py

datos_cuerda.txt: string
	./string > datos_cuerda.txt

string : cuerda.cpp
	g++ cuerda.cpp -o ./string > datos_cuerda.txt
