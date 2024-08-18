/* STRUCT */

typedef struct s_stack_node
{
	int			value;		// el valor en si
	int			pos;		// posicion actual en el stack
	bool			above_median;	// para determinar costes y direccion de rotacion
	struct s_stack_node	*target;	// pointer al nodo en B sobre el que colocamos el elemento de A
	struct s_stack_node	*next; 		// pointer al siguiente
	struct s_stack_node	*prev; 		// pointer al anterior
}				t_stack_node; 


/* MAIN */

0. se puebla el stack A con los numeros del array en el orden en que llegan (el primer elemento del array estara en el top de A)
	0.1. gestionar casos especificos
		0.1.1. errores (valores no numericos, repetidos, numeros demasiado grandes)
		0.1.2. llamadas sin parametros
		0.1.3. llamadas con menos de 4-5 numeros como parametro
		0.1.4. ??? varias string como parametro ???
1. push los dos primeros elementos de A a B
	1.1. determina el mayor y menor valor del stack B
2. se determina el coste de push para cada elemento de A (la funcion tiene un pointer al nodo mas "barato" que se actualiza solo si encuentra uno aun mas "barato")
	2.1. el coste es la distancia entre el elemento y la posicion top de cada stack; si ambos nodos estan sobre la media o bajo la media (pero no uno si y el otro no), el coste es la mayor distancia de las dos; en caso contrario seria la suma de las dos distancias
		2.1.1. el stack B esta ordenado de mayor a menor
		2.1.2. si el elemento de A es mayor que el max o menor que el min de B, el target es el valor maximo de B; actualiza el max/min de B
		2.1.3. si el elemento de A esta comprendido entre el maximo y minimo de B, se itera hasta encontrar un numero menor y se coloca encima
	2.2. si el coste del primer elemento en A es 0, dejar de mirar y push directamente
	2.3. si el menor coste corresponde a dos o mas elementos es el mismo, push el primero de ellos
3. se ejecutan las operaciones necesarias hasta hacer el push, imprimiendose en pantalla
4. se repiten los pasos 2 y 3 hasta que en el stack A quedan solo 3 numeros
5. se ordena el stack A de menor a mayor (esto cuesta entre 0 y 2 operaciones)
	5.1. todavia no nos importa el elemento top de cada stack, solo que esten ordenados
	5.2. se determina el max y min de A
6. se devuelven los elementos de B a A sin rotar B, solo A
	6.1. el stack A esta ordenado de menor a mayor
	6.2. si el elemento de B es mayor que el max o menor que el min de A, el target es el valor minimo de A; actualiza el max/min de A
	6.3. si el elemento de B esta comprendido entre el maximo y minimo de A, se itera hasta encontrar un numero menor y se coloca debajo
7. se coloca el min de A en el top

