# ProgramacionDeEstructurasDeDatos-Matriculacion
Programación de estructuras de datos y algoritmos fundamentales (Gpo 602)
El proyecto busca tomar una lista de nombres, la cual se podrá ordenar de manera alfabética de menor a mayor con el uso de los valores de las letras en ASCII, se podrá añadir más nombres a la lista, así como visualizarlo los nombres de la lista, buscar un nombre en específico para saber su posición en la lista y finalmente se podrá asignar una matrícula a cada nombre, dependiendo de su posición cuando son ordenamos alfabéticamente de mayor a menor.


El algoritmo usado para el ordenamiento de datos dentro del programa fue un mergeSort, este algoritmo, de manera muy general, va subdividiendo el total de los datos en pequeños fragmentos que se comparan entre sí y se ordenan, posteriormente estos pequeños fragmentos se comparan entre si y van formando conjunto cada vez más grandes; es decir se divide el problema en pedacitos y se va ordenando desde lo más bajo, creando conjuntos de datos que serán más fácil de ordenar cuando se miren en su totalidad, ya que estos ya están sub ordenados. La siguiente imagen de khan academy rescata de manera general el funcionamiento de este algoritmo.

![image](https://github.com/KevinJMLeyva/ProgramacionDeEstructurasDeDatos-Matriculacion/assets/145345829/2ead7044-438c-4fa9-bde0-595dd17e317b)

La complejidad de este algoritmo es de O(n)log(n), debido a que entre más se sube en el árbol recursivo más rápido será el ordenamiento, ya que entre más se sube en el árbol más ordenado se encuentran los datos, esto se debe a que ir ordenando pequeños conjuntos es más rápido que ordenar todos los datos sin ningún orden. Un ejemplo sencillo para entender esto es armar un rompecabezas, ya que si buscas exactamente la pieza que encaja con otro pieza tardarás más tiempo que si vas armando “pedazos” de figuras y posteriormente los unes con otros “pedazos” que ya has armado. 


El algoritmo de búsqueda es una búsqueda binaria recursiva, se uso está debido a que se trabajaría con un conjunto de datos ordenados o al menos cuando se busque un nombre debería de interesar su posición cuando el conjunto ya este ordenado alfabéticamente, gracias a esta ventaja es que se puede utilizar este método, no obstante se le hizo una pequeña modificación, ya que el valor que se busca es solamente la primera letra del nombre  de la persona, por lo que cuando la primera letra (en valor número de su representación en ASCII) coincida con un valor del vector de datos se tomará un valor a la izquierda y otro a la derecha que comparará el valor total de todos los caracteres del nombre que se busca con el valor de todos los caracteres que se encuentran en el vector, para si asegurarse de que se encontró el nombre que se buscaba. 

# Proyecto Avance 2 estructuras
SICT0301: Evalúa los componentes
La estructura de datos utilizada fue una lista ligada doble que puede llegar a tener una complejidad de o(1), si supones que siempre hay algo apuntando al elemento, pero en el peor de los casos se comporta como una lista común y corriente con una complejidad de o(n).

Lo anteriormente mencionado se refiere a la consulta de los datos, pero para su ordenamiento se uso un algoritmo de merge sort que tiene una complejidad de O ( n log n ) y que interactua de manera directa con la lista doblemente ligada, es decir que no crea un vector o agreglo extra en donde se orden los datos y posteriormentse se asignen a la lista doblemente liga, sino que interactua directamente con los nódos y sus valores, agilizando el proceso.

SICT0302: Toma decisiones
En este caso se uso una lista ligada doble, ya que es una herramienta con más versalitidad que una lista común y corriente, un ejemplo de esto es la implemetación del get del nombre del alumno, ya que esta posee una complejidad de o(n/2), por lo que mejora enormemente con respecto a un vector, o lista simple.

SICT0303: Implementa acciones científicas

Como se mentior anterior mente se utilizo la capacidad que tiene la lista de su vinculación con parte izquierda y derecha, por lo que si queremos acceder a un elemento por medio de su index, podemos determinar de manera rápida desde que punto debemos partir (tomando en cuenta que nos posicionamos en el centro), situación que disminute la complejidad de está acción.

Los datos fueron extraído de un archivo .txt, el cual alamecena 139 nombre diferentes, y que son usados en el porgrama. Para alamacenar estos datos, el archivo de texto se fue leyendo línea por línea y cada valor de la línea era asignado a un nodo que forma parte de nuestra lista ligada doble.

# Proyecto Avance 3 estructuras

Para el Avance 3 se perfecciono el algoritmo de ordenamiento de la lista y se agregaron algunas funciones nuevas, siguiendo con la estructura DBL (Double Linked List).
 
SICT0301: Evalúa los componentes

Para el análisis de complejidad se analizaran las principales funciones del programa, en donde se pondrá el nombre de la función en el menú y la función de la clase usada:   
1.Visualizar alumnos.alumnos.print(); Para la visualización de los datos tenemos una complejidad de N, ya que no hay otra opción más que reccorrer la lista en su totalidad, para mostrar todos los elementos que la componen. 

2. Ordenar alumnos por orden alfabetico. alumnos.ordena(); Para el ordenamiento de la lista se uso un mergesort, algoritmo que posee una complejidad de o(n)log(n). A grandes rasgos el algoritmo segmenta la lista y ordena segmentos de la lista, para después unirla, ya que esto es más rápido que ordenar una lista desde cero. En los anteriores avances se describe de mejor manera el funcionamiento del mergesort.  
 
3.Añadir alumno.alumnos.addFirst(nuevo_alumno); Está función tiene una complejidad de 1, ya que usamos las propiedades de la DBL para ponerlo en la primera posición, en esta misma función ordenamos la lista, usando el merge sort, por lo que la función tiene una complejidad de O(n)log(n). 

4.Buscar alumno. alumnos.get(index1); para esta función se posee una complejidad de n/2, ya que parte de la mitad del arreglo y se determina si el index es mayor o menor al index intermedio del agrego.  
 
5.Asignar matrículas.  alumnos.printMatriculas(); complejidad de N, ya que se debe recorrer todos los elementos de la lista. 

6.Guardar cambios. alumnos.guardarMatriculas(nombre_archivo_matriculas_pred); compeljidad de N, ya que se debe recorrer todos los elementos de la lista.

7.Modificar alumno.  alumnos.set(alumno_modifico,alumno_nombre); para esta función se posee una complejidad de n/2, ya que parte de la mitad del arreglo y se determina si el index es mayor o menor al index intermedio del arreglo.  

En conclusión, cuando se trata de modificar datos o hacer una consulta se posee una complejidad de n/2, en caso de recorrer toda la lista una complejidad de N y en el caso de ordenar la lista se tiene una complejidad O(n)log(n), gracias al mergesort

SICT0303: Implementa acciones científicas

El programa incluye la opción de guardar la lista ordenada de los alumnos, con su correspondiente matrícula en un archivo txt, además da la posibilidad de elegir la ruta en donde se quiera guardar el archivo.
