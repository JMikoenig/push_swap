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



/* ========================================== */

int	str_separate(char *srcstr, char sep, char ***output)
{
	/* Assume we have a properly NULL-terminated string. */
	int		len = strlen(srcstr);

	/* Initialize the number of tokens to 0. */ 
	int		numparts = 0;

	/* A temporary pointer to a char pointer we'll use later. */
	char	**currentpart;
	
	/* 
	 * Replace every instance of sep with a NULL character. 
	 * This has the effect of turning one string into many; you can
	 * think of the first string beginning where the original string
	 * did, and ending at the first NULL, then the second string
	 * beginning at the character right after that NULL.
	 */
	int	i;
	for (i = 0; i < len; i++)
	{
		if (srcstr[i] == sep)
		{
			srcstr[i] = '\0';	
			numparts++;
		}
	}

	/* 
	 * Increment numparts one more time, for the last substring. 
	 * i.e. if we found N separators we have N+1 parts. If two
	 * separator characters appear together, or there is a 
	 * separator at the end, then some of these become the empty
	 * string "".
	 */
	numparts++;
	
	/* Allocate space for our pointers to the various substrings
	 * Note that here we dereference output once, to assign to the
	 * char ** we declared in the calling function (i.e. main())
	 */
	*output = malloc(numparts * sizeof(char *));

	/* You should always check the return value of malloc! */
	if (*output == NULL)
	{
		perror("malloc() call in str_separate");
		exit(1);
	}
	
	/* Start with currentpart pointing to the first allocated pointer.
	 * We'll use this to step through the array of char * pointers.
	 */
	currentpart = *output;

	/*
	 * The first char * pointer should point to the beginning of the 
	 * original string, as that is necessarily the first token.
	 */
	*currentpart = srcstr;
	
	/* 
	 * We've placed \0's in the place of every occurrence of sep; so
	 * a new token/substring begins at the character AFTER a \0
	 * (excluding the very last \0, which we will never hit with this
	 * loop).
	 * 
	 * This loop finds all the NULLs we placed in the string, and stores
	 * a pointer to the character after each NULL in *currentpart, after
	 * incrementing currentpart to move to the next char * slot.
	 */
	
	for (i = 0; i < len; i++) /* < len: we never get to the last '\0', 
							   * since strlen gives us the length of
							   * the string, not including the NULL */
	{
		if (srcstr[i] == '\0') {
						while(srcstr[i+1] == '\0') {
				i++;
				numparts --;
			}
			currentpart++;
			*currentpart = &(srcstr[i+1]);
		}
	}
	
	/* 
	 * We only return the integer numparts, but in fact we are 
	 * "implicitly returning" the contents of *output, since this
	 * was declared outside str_separate but modified by it.
	 */
	return (numparts);
}