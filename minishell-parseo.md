# Minishell - Parseo

La construcción de un shell minimalista como el Minishell, se puede tratar como un lenguaje de tipo 4 (lenguaje regular) en cuanto al análisis léxico.

# Máquinas de Estado

## Niveles de Lenguaje
Los lenguajes se clasifican en cuatro niveles según su complejidad y las máquinas de estado necesarias para analizarlos.

1. **Nivel 1 (Lenguaje Natural)**:
   - **Ejemplos**: Español, Inglés.
   - **Características**: 
     - Son lenguajes muy complejos, con reglas gramaticales y semánticas complicadas.
     - No siguen una estructura estricta y permiten una gran flexibilidad.
     - Para su análisis, se necesita una comprensión profunda del contexto y significado, lo que requiere algoritmos avanzados de procesamiento de lenguaje natural (PLN).
   - **Aplicaciones**: Procesamiento de textos, comprensión de lenguaje natural, chatbots.

2. **Nivel 2 (Lenguaje de Pilas)**:
   - **Ejemplos**: Lenguajes con corchetes balanceados como `{}` en C/C++.
   - **Características**:
     - Necesitan una pila para su análisis, ya que deben mantener un seguimiento de los elementos anidados.
     - Se utilizan para lenguajes donde la correspondencia de apertura y cierre es crucial, como en expresiones aritméticas o estructuras de control.
     - Ejemplo: El lenguaje que requiere que para cada `a^n` haya un correspondiente `c^n`, como en `a^n b c^n`.
   - **Aplicaciones**: Validación de expresiones aritméticas, parsers de código fuente.

3. **Nivel 3 (Lenguaje Context-Free)**:
   - **Ejemplos**: Lenguajes de programación como Python, Java.
   - **Características**:
     - Definidos por gramáticas libres de contexto, lo que permite producir estructuras de sintaxis complejas como árboles de derivación.
     - No requieren una pila explícita para su análisis, pero sí un análisis sintáctico más complejo.
   - **Aplicaciones**: Parsers de lenguajes de programación, análisis sintáctico en compiladores.

4. **Nivel 4 (Lenguaje Regular)**:
   - **Ejemplos**: Expresiones regulares como `ab*c`.
   - **Características**:
     - Definidos por expresiones regulares y pueden ser reconocidos por autómatas finitos.
     - Son los más simples de analizar y no requieren memoria adicional como una pila.
   - **Aplicaciones**: Validación de patrones de texto, búsquedas y reemplazos en editores de texto.

## Máquinas de Estado
### Máquina Finita Determinista (DFA)
- **Definición**: Una máquina de estado en la que, para cada estado y entrada, hay una única transición posible.
- **Características**:
  - **Determinismo**: En cada estado, dado un símbolo de entrada, siempre se sabe a qué estado transitar.
  - **Estado Sumidero**: Se puede agregar un estado sumidero para manejar entradas no válidas. Este estado absorbe cualquier entrada no válida y permanece en él.
- **Ejemplo**:
  - Para un lenguaje `ab*c`, un DFA tendría estados que transitan de `a` a `b` y luego permiten múltiples `c`.

### Máquina Finita No Determinista (NFA)
- **Definición**: Una máquina de estado en la que, para un estado y entrada, puede haber múltiples transiciones posibles.
- **Características**:
  - **No Determinismo**: En cada estado, dado un símbolo de entrada, puede haber varias posibles transiciones.
  - **Transiciones Epsilon (ε)**: Permiten transiciones sin consumir ningún símbolo de entrada.
- **Ejemplo**:
  - Para un lenguaje `ab*c`, un NFA podría tener estados que permiten tanto `b` como `c` simultáneamente desde el mismo estado.

## Análisis de Lenguaje
### Análisis Léxico y Sintáctico
1. **Análisis Léxico**:
   - **Función**: Divide una cadena de entrada en tokens, que son las unidades básicas de sintaxis como palabras y símbolos.
   - **Proceso**:
     - **Tokenización**: Separar la cadena en componentes significativos.
     - **Clasificación**: Identificar el tipo de cada token (por ejemplo, identificador, número, operador).
   - **Ejemplo**: 
     - Entrada: "Yo me gusta Alex"
     - Tokens: ["Yo", "me", "gusta", "Alex"]

2. **Análisis Sintáctico**:
   - **Función**: Verifica si la secuencia de tokens sigue las reglas gramaticales del lenguaje.
   - **Proceso**:
     - **Parser**: Construye un árbol de derivación que representa la estructura gramatical.
     - **Verificación de Reglas**: Asegura que la secuencia de tokens es válida según la gramática.
   - **Ejemplo**:
     - Entrada: ["Yo", "me", "gusta", "Alex"]
     - Verificación: Determina si "Yo me gusta Alex" tiene sentido gramatical.

#### Ejemplos de Análisis:
- "Yo me llamo mesa" (No tiene sentido semántico).
- "Yo me gusta Alex" (Tiene sentido gramaticalmente pero no semánticamente).

### Tokenización
- **Función**: Transformar una cadena de caracteres en tokens para facilitar el análisis.
- **Ejemplo**: 
  - Entrada: "Yo me llamo mesa"
  - Tokens: ["Yo", "me", "llamo", "mesa"]
- **Validación Semántica**:
  - "Yo me llamo mesa" no tiene sentido semántico porque "mesa" no es un nombre válido en este contexto.

## Minishell: Análisis Léxico y Sintáctico
### Ejemplo de Comando
```sh
ls -la | cat > hola.txt
```
### Proceso
1. **Análisis Léxico**:
   - Divide la cadena en tokens: ["ls", "-la", "|", "cat", ">", "hola.txt", ]
2. **Análisis Sintáctico**:
   - Verifica la validez de la secuencia y estructura los comandos para su ejecución.
   - **Sintaxis**: Comprueba la estructura y orden de los tokens.

### Implementación en Minishell
- Utiliza dos máquinas de estado: una para el análisis léxico y otra para el análisis sintáctico.

## Ejemplo de Estado Léxico
### Estados Léxicos:
- **Estado Inicial (S)**: Estado de inicio.
- **Estado `WORD` (W)**: Se transita a este estado al encontrar letras y números.

```sh
ls -la
```
1. **Estado Inicial (S)**: Al encontrar una letra, transita al estado `WORD`.
2. **Estado `WORD` (W)**: Continúa hasta encontrar un espacio o símbolo especial.

## Lexer y Parser
### Lexer: No hay Acciones

En esta parte no se genera nada nuevo, solo se comprueba si pertenece a un lenguage o no.

Nexo de ambas:

r = lexer ("ls .la")
c = parser(r)

#### Estados del Lexer:

1. **Estado Inicial (S)**:
   - `ls -ls` -> `word ls`, `word -l`.
2. **Estado `WORD` (W)**:
   - Transita al encontrar letras.

Otros estados: el de comilla simple, comilla doble, símbolo de dolar.

### Manejo de Comillas y Variables
- **Comillas Simples y Dobles**:
  - **Comillas Simples (`'`)**: Al encontrar una comilla simple, se transita a un estado especial y se escapan caracteres hasta encontrar otra comilla simple.
  - **Comillas Dobles (`"`)**: Similar a las comillas simples, pero permiten sustituciones de variables dentro de ellas.
- **Variable `$`**:
  - **Manejo de `$`**: Cuando se encuentra `$`, se transita al estado de sustitución. La variable termina al encontrar un espacio o símbolo especial.
  - **Estados Especiales**:
    - **Estado de Sustitución (`$`)**: Maneja variables y su expansión dependiendo del contexto (comilla simple, doble, o palabra).

#### Ejemplo de Lexer:
```c
enum state{
    S, Q, W, DOLLAR
}

next_state(state s, char c)
```

## Parser: Acciones

El input puede ser word, pipe, redireccion > < >> << 

Mi maquina de estado tiene q estar cerrado a estos inputs: se puede hacer con una estructura enum.

Con las acciones creamos la lista. En el parser es donde se ejecutan las acciones. 

Ejemplo para el comando ls -la:

ls -la: encuentro "l" creo la acción "crear palabra", seguimos, encuentro "s", creo acción "añado palabra", seguimos, encuentro espacio, entonces me voy del estado W y vuelvo a estado S, seguimos, encuentro "-", creo otra palabra, y así sucesivamente.

No es necesario q tras una pipe sin comando detrás se tenga que quedar esperando, esto se puede gestionar como error. Viene en el subject.

Cualquier redirección seguida de un pipe tal q asi >| sin espacio, es incorrecto, aquí la pipe iría al estado sumidero.

Principal del parser: si tenemos muchas palabras si me encuentro un | entonces todo lo anterior es un comando y se crea un nodo con todo ello sin el pipe, el pipe lo ignoramos y formo otro nodo con otro comando y así me creo la lista.

Desde pipe - acción crear nuevo nodo. Se pueden usar las funciones de listas de la libft haciendo un casteo y te ahorras hacer todas estas funciones.

Contenido el nodo: argc, comando, fd_in, fd_out

### Redirecciones:

- >
Cuando encontramos > tendrá una acción y creará un fd_out (fd_out se habrá inicializado a cero previamente). Si a continuación encontramos un word, entonces usamos open, abrimos el archivo y guardamos el fd en fd_out y si enc otro > entonces usas close, y repetimos.

- < 
Asigna el fd_in al encontrar el word tras el open. 

De manera que seguira abriendo archivos y al ejecutor le llega el último, da igual cuántos infiles haya o tantos outfile haya.

El open tienes q hacerlo con la flag adecuada dependiendo del signo en el parseo de modo q al ejecutor le llega el fd nada mas.

Es importante seguir este funcionamiento porque la shell funciona exactamente así. De este modo si el ejecutor encuentra un fallo al ejecutar algún comando, los archivos ya previamente se habrán creado o abierto tantos como se indicara en el argv y en el último se ejecutará lo que venga indicado para el caso. Es por ello importante que todos los archivos se gestionen en el parseo y al ejecutor solo llegue los últimos fdin y fdout.

## Parseo y Ejecutor

1. **Parseo**:
   - Convierte la lista de tokens en una estructura de comandos.
   - **Estructura de Comando**:
     ```c
     typedef struct command {
         int argc;
         char **argv;
         int fd_in;
         int fd_out;
     } t_command;
     ```
2. **Ejecutor**:
   - Ejecuta los comandos según la estructura parseada.

# Recomendaciones: usar una lista simple enlazada en la que se incluya en cada nodo los comandos x ej (ls -la), el fdin, fdout que corresponderán al último archivo encontrado o generado y el argc

## Apertura y Generación de Archivos en Minishell

En un shell como Bash, la manipulación de archivos es fundamental, especialmente cuando se trata de redirecciones (`>`, `<`, `>>`, `<<`). Aquí detallamos cómo manejar estas operaciones en un minishell.

### Redirección de Salida (`>`)
- **Función**: Redirigir la salida estándar de un comando a un archivo.
- **Proceso**:
  1. **Identificar el Token**: Durante el análisis léxico, se identifica el token `>`.
  2. **Abrir el Archivo**: En el parser, se abre el archivo especificado para escritura.
  3. **Asignar `fd_out`**: El descriptor de archivo se asigna al campo `fd_out` del comando.

### Redirección de Entrada (`<`)
- **Función**: Redirigir la entrada estándar de un comando desde un archivo.
- **Proceso**:
  1. **Identificar el Token**: Durante el análisis léxico, se identifica el token `<`.
  2. **Abrir el Archivo**: En el parser, se abre el archivo especificado para lectura.
  3. **Asignar `fd_in`**: El descriptor de archivo se asigna al campo `fd_in` del comando.

### Redirección de Salida Append (`>>`)
- **Función**: Redirigir la salida estándar de un comando a un archivo, anexando en lugar de sobrescribir.
- **Proceso**:
  1. **Identificar el Token**: Durante el análisis léxico, se identifica el token `>>`.
  2. **Abrir el Archivo**: En el parser, se abre el archivo especificado para escritura en modo append.
  3. **Asignar `fd_out`**: El descriptor de archivo se asigna al campo `fd_out` del comando.

### Heredoc (`<<`)
- **Función**: Permitir la entrada de múltiples líneas hasta que se encuentra una línea específica (delimiter).
- **Proceso**:
  1. **Identificar el Token**: Durante el análisis léxico, se identifica el token `<<`.
  2. **Crear Archivo Temporal**: Se crea un archivo temporal para almacenar la entrada del heredoc.
  3. **Leer Entrada**: Se lee la entrada del usuario línea por línea hasta encontrar el delimiter.
  4. **Asignar `fd_in`**: El descriptor de archivo del archivo temporal se asigna al campo `fd_in` del comando.

### Manejo de File Descriptors en la Ejecución
Una vez que los descriptores de archivo (`fd_in`, `fd_out`) están asignados en la estructura del comando, se deben redirigir los descriptores estándar durante la ejecución del comando.

## Manejo de Múltiples Redirecciones en Minishell

En un shell como Bash, es posible encontrar múltiples redirecciones en un solo comando. Es importante gestionar estas redirecciones correctamente, asegurando que los descriptores de archivo (`fd_in` y `fd_out`) se actualicen adecuadamente a medida que se procesan.

### Principios de Funcionamiento

- **Redirecciones Múltiples**: Al analizar un comando, se pueden encontrar múltiples redirecciones (`>`, `<`, `>>`, `<<`).
- **Actualización de Descriptores de Archivo**: Los descriptores de archivo (`fd_in` y `fd_out`) se inicializan y actualizan conforme se procesan las redirecciones. 
  - **`fd_in`**: Se utiliza para redirecciones de entrada (`<`).
  - **`fd_out`**: Se utiliza para redirecciones de salida (`>`, `>>`).

### Proceso de Manejo de Redirecciones

1. **Inicialización**: `fd_in` se inicializa a `0` y `fd_out` a `0`.
2. **Análisis y Actualización**: 
   - Al encontrar una redirección de entrada (`<`), se abre el archivo especificado y `fd_in` se actualiza con el nuevo descriptor de archivo.
   - Al encontrar una redirección de salida (`>` o `>>`), se abre o crea el archivo especificado y `fd_out` se actualiza con el nuevo descriptor de archivo.
3. **Última Redirección**: El valor final de `fd_in` y `fd_out` corresponde a los descriptores de archivo del último archivo abierto o creado.

Esta estructura permite que el shell gestione múltiples redirecciones de manera eficiente, asegurando que siempre se utilicen los descriptores de archivo correctos para la entrada y salida de comandos.

# Ejecutor en Minishell

El ejecutor es responsable de recibir los comandos parseados y los fds, comprobar su validez, y ejecutarlos. Además, maneja comandos internos que no tienen una ruta específica en el sistema.