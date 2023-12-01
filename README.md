# ProgramacionDeEstructurasDeDatos-Matriculacion
Programación de estructuras de datos y algoritmos fundamentales (Gpo 602)
El proyecto busca tomar una lista de nombres, la cual se podrá ordenar de manera alfabética de menor a mayor con el uso de los valores de las letras en ASCII, se podrá añadir más nombres a la lista, así como visualizarlo los nombres de la lista, buscar un nombre en específico para saber su posición en la lista y finalmente se podrá asignar una matrícula a cada nombre, dependiendo de su posición cuando son ordenamos alfabéticamente de mayor a menor.


El algoritmo usado para el ordenamiento de datos dentro del programa fue un mergeSort, este algoritmo, de manera muy general, va subdividiendo el total de los datos en pequeños fragmentos que se comparan entre sí y se ordenan, posteriormente estos pequeños fragmentos se comparan entre si y van formando conjunto cada vez más grandes; es decir se divide el problema en pedacitos y se va ordenando desde lo más bajo, creando conjuntos de datos que serán más fácil de ordenar cuando se miren en su totalidad, ya que estos ya están sub ordenados. La siguiente imagen de khan academy rescata de manera general el funcionamiento de este algoritmo.

![image](https://github.com/KevinJMLeyva/ProgramacionDeEstructurasDeDatos-Matriculacion/assets/145345829/2ead7044-438c-4fa9-bde0-595dd17e317b)

La complejidad de este algoritmo es de O(n)log(n), debido a que entre más se sube en el árbol recursivo más rápido será el ordenamiento, ya que entre más se sube en el árbol más ordenado se encuentran los datos, esto se debe a que ir ordenando pequeños conjuntos es más rápido que ordenar todos los datos sin ningún orden. Un ejemplo sencillo para entender esto es armar un rompecabezas, ya que si buscas exactamente la pieza que encaja con otra pieza tardarás más tiempo que si vas armando “pedazos” de figuras y posteriormente los unes con otros “pedazos” que ya has armado.

El algoritmo de búsqueda es de O(n/2), ya que siempre que se busque la lista está ordenada, por lo que podemos partir del centro de la lista y valorar si el elemento que buscamos es menor o mayor que el que se encuentra en la mitad de la lista.ç
SICT0302 Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

En este caso se usó una lista ligada doble, ya que es una herramienta con más versatilidad que una lista común y corriente, un ejemplo de esto es la implementación del get del nombre del alumno, ya que esta posee una complejidad de o(n/2), por lo que mejora enormemente con respecto a un vector, o lista simple. Sumado a lo anterior la implementación de algoritmos de ordenamiento se facilita, ya que es parecido a ordenar un arreglo normal.


**SICT0301: Evalúa los componentes**

**SICT0301:** Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El algoritmo de ordenamiento usado es un merge sort, es el único utilizado en el programa y tiene una complejidad de O(n)log(n)

**SICT0301:** Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
La estructura de datos utilizada fue una lista ligada doble que puede llegar a tener una complejidad de o(1), si hay algo apuntando al elemento, pero en el peor de los casos se comporta como una lista común y corriente con una complejidad de o(n).

Lo anteriormente mencionado se refiere a la consulta de los datos, pero para su ordenamiento se usó un algoritmo de merge sort que tiene una complejidad de O (n)log(n) y que interactúa de manera directa con la lista doblemente ligada, es decir que no crea un vector o arreglo extra, se en donde se ordenenlos datos y posteriormente se asignen a la lista doblemente liga, sino que interactúa directamente con los nodos y sus valores, agilizando el proceso.

**SICT0301:** Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Para el análisis de complejidad se analizaran las principales funciones del programa, en donde se pondrá el nombre de la función en el menú y la función de la clase usada:
1.Visualizar alumnos.alumnos.print(); Para la visualización de los datos tenemos una complejidad de O(n), ya que no hay otra opción más que recorrer la lista en su totalidad, para mostrar todos los elementos que la componen.

2.Ordenar alumnos por orden alfabético. alumnos.ordena(); Para el ordenamiento de la lista se usó un mergesort, algoritmo que posee una complejidad de o(n)log(n). A grandes rasgos el algoritmo segmenta la lista y ordena segmentos de la lista, para después unirla, ya que esto es más rápido que ordenar una lista desde cero. En los anteriores avances se describe de mejor manera el funcionamiento del mergesort.

3.Añadir alumno.alumnos.addFirst(nuevo_alumno); Está función tiene una complejidad de O(1), ya que usamos las propiedades de la DBL para ponerlo en la primera posición, en esta misma función ordenamos la lista, usando el merge sort, por lo que la función tiene una complejidad de O(n)log(n).

4.Buscar alumno. alumnos.get(index1); para esta función se posee una complejidad de O(n/2), ya que parte de la mitad del arreglo y se determina si el index es mayor o menor al index intermedio de la lista doblemente ligada,

5.Asignar matrículas. alumnos.printMatriculas(); complejidad de O(n), ya que se debe recorrer todos los elementos de la lista.

6.Guardar cambios. alumnos.guardarMatriculas(nombre_archivo_matriculas_pred); compeljidad de O(n), ya que se debe recorrer todos los elementos de la lista.

7.Modificar alumno. alumnos.set(alumno_modifico,alumno_nombre); para esta función se posee una complejidad de O(n/2),ya que parte de la mitad del arreglo y se determina si el index es mayor o menor al index intermedio del arreglo.

En conclusión, cuando se trata de modificar datos o hacer una consulta se posee una complejidad de  O(n/2), en caso de recorrer toda la lista una complejidad de O(n) y en el caso de ordenar la lista se tiene una complejidad O(n)log(n), gracias al mergesort

**SICT0303:** Implementa acciones científicas

**SICT0303:** Implementa mecanismos para consultar información de las estructuras correctas.
Como se mencionó anteriormente se utilizó la capacidad que tiene la lista de su vinculación con parte izquierda y derecha, por lo que si queremos acceder a un elemento por medio de su index, podemos determinar de manera rápida desde que punto debemos partir (tomando en cuenta que nos posicionamos en el centro), situación que disminuye la complejidad de está acción.Esta es la opción 5 del menú.

En caso de querer visualizar toda la lista, simplemente recorreremos cada nodo de la lista doblemente ligada, hasta llegar a su final. Esto describe la opción 1 y 6.

**SICT0303:** Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Los datos fueron extraídos de un archivo .txt, el cual almacena 139 nombres diferentes, y que son usados en el programa. Para almacenar estos datos, el archivo de texto se fue leyendo línea por línea y cada valor de la línea era asignado a un nodo que forma parte de nuestra lista ligada doble.

**SICT0303:** Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.
El programa incluye la opción de guardar la lista ordenada de los alumnos, con su correspondiente matrícula en un archivo txt, además da la posibilidad de elegir la ruta en donde se quiera guardar el archivo. Esta es la opción 7 del menú.









