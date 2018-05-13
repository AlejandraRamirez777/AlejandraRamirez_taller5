placas.png: datos_placas.txt
	python grafica.py

datos_placas.txt: plate
	./plate > datos_placas.txt

plate : placas.cpp
	g++ placas.cpp -o ./plate > datos_placas.txt
