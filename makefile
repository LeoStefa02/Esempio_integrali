LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main: main.cpp ./FunzioniUtili/funzioni.h ./Integrali/Integral.h ./EquazioniDifferenziali/EquazioniDifferenziali.h
	g++ main.cpp -o main ${LIBS} ${INCS} -I/home/leonardo/anaconda3/envs/dev/include/

calcola: calcola.cpp ./FunzioniUtili/funzioni.h ./Integrali/Integral.h ./EquazioniDifferenziali/EquazioniDifferenziali.h
	g++ calcola.cpp -o calcola ${LIBS} ${INCS} -I/home/leonardo/anaconda3/envs/dev/include/