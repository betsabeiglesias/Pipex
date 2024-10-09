# 🛠️ Pipex - ¡Haciendo magia con pipes!

¡Bienvenid@ a mi implementación de **Pipex**! 🎉 Este proyecto es una forma genial de entender cómo funcionan los pipes en UNIX/Linux y cómo podemos combinarlos con comandos. Si alguna vez te has preguntado qué está pasando cuando encadenas comandos en la terminal, ¡este proyecto te lo mostrará! 🤓

## 🚀 ¿Qué hace Pipex?

Este programa toma dos archivos y dos comandos, y utiliza pipes para conectar la salida del primer comando con la entrada del segundo, como si estuvieras haciendo:

![ejemplo](img1.png)

De modo que esto:

![ejemplo](img2.png)

hará lo mismo que:

![ejemplo](img3.png)

### 🎯 Uso
- **archivo1**: El archivo del que se lee la entrada.
- **archivo2**: El archivo donde se guarda la salida.
- **comando1 y comando2**: Comandos que se encadenan con un pipe.

![ejemplo](img4.png)

Ejemplo: para contar el número de líneas de un archivo.  
Si quisiéramos leer las líneas de un archivo de manera tradicional en la terminal, tendríamos que ejecutar lo siguiente:

![ejemplo](img5.png)

Esto toma el contenido de `infile`, lo pasa por `cat`, y luego cuenta las líneas con `wc -l`, guardando el resultado en `outfile`.

Con **Pipex**, este mismo proceso se puede ejecutar de la siguiente manera:

![ejemplo](img6.png)

### 🔥 Bonus Features (¡Porque lo valgo! 😎)

Además de las funcionalidades básicas de **Pipex**, he implementado algunas mejoras extra para hacerlo aún más versátil y potente. Estas características adicionales permiten manejar casos más complejos y hacer que el programa sea mucho más útil en escenarios avanzados.

#### 1. Soporte para múltiples pipes

En la versión estándar de **Pipex**, trabajamos con solo dos comandos, pero en esta versión mejorada, ¡puedes encadenar tantos comandos como quieras! 🎉

Esto te permite crear una serie de operaciones utilizando múltiples pipes, donde la salida de cada comando se convierte en la entrada del siguiente. El uso es sencillo:

![ejemplo](img7.png)

Este comando es equivalente a lo siguiente en la terminal:

![ejemplo](img8.png)

Ahora puedes pasar por varios comandos intermedios y redirigir la salida final a `archivo2`. Ideal para cuando necesitas procesar datos a través de múltiples etapas en un solo flujo continuo.

#### 2. Soporte para **Here_doc** con redirecciones `<<` y `>>`

Otra característica útil es el soporte para **here_doc**, que permite capturar múltiples líneas de entrada en un archivo temporal hasta que se encuentre un delimitador especificado. Esto es especialmente útil cuando necesitas proporcionar entrada directamente desde la línea de comandos sin depender de un archivo externo.

El formato para usar **here_doc** es el siguiente:

![ejemplo](img9.png)

Este comando ejecutará `comando1`, tomando la entrada directamente desde el terminal o un archivo hasta que se encuentre la palabra `LIMITADOR`. La salida de `comando1` será pasada a `comando2` y finalmente redirigida a `archivo2` usando el operador `>>`, que añadirá el resultado al archivo sin sobrescribir su contenido.

Es equivalente a ejecutar:

![ejemplo](img10.png)
