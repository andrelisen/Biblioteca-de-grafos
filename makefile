index:
	#construindo projeto	
	gcc funcao.c -c -g
	gcc busca.c -c -g
	gcc heap.c -c -g
	gcc guloso.c -c -g
	gcc main.c busca.o funcao.o heap.o guloso.o -o exec -g
clear: 	
	#limpando o arquivo
	rm funcao.o
	rm busca.o 
	rm heap.o 
	rm guloso.o 
	rm exec
