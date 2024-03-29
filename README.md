1. Comprobar las nuevas funciones con los tests
2. meter ejemplos

<h1 align="center">🖖  MyLibft  🖖</h1>

<p align="center"><b><i>A COMPILATION OF ALL THE FUNCTIONS I HAVE CREATED AND USED IN THE 42's CURSUS PROJECTS</i></b><br></p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Sant-TIG/mylibft?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/Sant-TIG/mylibft?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/Sant-TIG/mylibft?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Sant-TIG/mylibft?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Sant-TIG/mylibft?color=green" />
</p>

<h3 align="center">
	<a href="#memory-functions">Memory</a>
	<span> · </span>
	<a href="#strings-functions">Strings</a>
	<span> · </span>
	<a href="#convert-functions">Convert</a>
	<span> · </span>
	<a href="#check-functions">Check</a>
</h3>

---

## Memory Functions
|FUNCIONES|DESCRIPCION|VALOR DE RETORNO|
|:-:|:-:|:-:|
|[ft_memchr](https://github.com/Sant-TIG/mylibft/blob/master/memory%20functions/ft_memchr.c)|Busca la primera aparicion de un caracter en los primeros n bytes de un espacio de memoria|- Puntero al caracter<br>- NULL|
|[ft_memcmp](https://github.com/Sant-TIG/mylibft/blob/master/memory%20functions/ft_memcmp.c)|Compara el contenido de los primeros n bytes de dos espacios de memoria|-Mayor que cero<br>- Cero<br>- Menor que cero|
|[ft_memcpy](https://github.com/Sant-TIG/mylibft/blob/master/memory%20functions/ft_memcpy.c)|Copia n bytes de un area de memoria en otra. Las memorias no deben superponerse|- Puntero al area de memoria de destino<br>- NULL|
|[ft_memmove](https://github.com/Sant-TIG/mylibft/blob/master/memory%20functions/ft_memmove.c)|Copia n bytes de un area de memoria en otra. Las memorias pueden superponerse|- Puntero al area de memoria de destino<br>- NULL|
|[ft_memset](https://github.com/Sant-TIG/mylibft/blob/master/memory%20functions/ft_memset.c)|Copia un caracter en los primeros n bytes de un espacio de memoria|-Puntero al espacio de memoria|

## Strings Functions
|FUNCIONES|DESCRIPCION|VALOR DE RETORNO|
|:-:|:-:|:-:|
|[ft_stpcpy](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_stpcpy.c)|Copia una cadena en otra. Puede reemplazar a la funcion ft_strcat(). Las memorias no deben superponerse|- Puntero al final de la cadena de destino|
|[ft_stpncpy](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_stpncpy.c)|Copia n bytes de una cadena en otra. Rellena exactamente n bytes en la cadena de destino|- Puntero al ultimo byte de la cadena de destino|
|[ft_strcasecmp](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strcasecmp.c)|Compare two strings ignoring the case of their characters|-Mayor que cero<br>- Cero<br>- Menor que cero|
|[ft_strcasestr]()|||
|[ft_strcat]()|||
|[ft_strchr](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strchr.c)|Busca la primera aparicion de un caracter en una cadena| - Puntero al caracter<br>- NULL|
|[ft_strchrnul](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strchrnul.c)|Busca la primera aparicion de un caracter en una cadena| - Puntero al caracter<br>- Puntero al caracter nulo|
|[ft_strcmp](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strcmp.c)|Compara si dos cadenas son iguales|-Mayor que cero<br>- Cero<br>- Menor que cero|
|[ft_strcpy](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strcpy.c)|Copia una cadena en otra. Las memorias no deben superponerse|- Puntero a la cadena de destino.|
|[ft_strlcat]()|||
|[ft_strlcpy](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strlcpy.c)|Copia n - 1 bytes de una cadena a otra, terminando con un caracter nulo. Reemplazo de la funcion ft_strncpy()|- Longitud de la cadena que se va a copiar|
|[ft_strlen](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strlen.c)|Calcula la longitud de una cadena|- El numero de bytes de la cadena<br>- Cero|
|[ft_strmapi](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strmapi.c)|Aplica una funcion a cada caracter de una cadena|- Puntero a la nueva cadena<br>- NULL|
|[ft_strncasecmp]()|||
|[ft_strncat]()|||
|[ft_strncmp](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strncmp.c)|Compara si los primeros n bytes de dos cadenas son iguales|-Mayor que cero<br>- Cero<br>- Menor que cero|
|[ft_strncpy]()|||
|[ft_strnstr](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strnstr.c)|Busca la primera aparicion de una subcadena en los primeros n bytes de una cadena|- Puntero a la subcadena<br>-Puntero a la cadena<br>- NULL|
|[ft_strrchr](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strrchr.c)|Busca la ultima aparicion de un caracter en una cadena| - Puntero al caracter<br>- NULL|
|[ft_strstr](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_strstr.c)|Busca la primera aparicion de una subcadena en una cadena|- Puntero a la subcadena<br>- NULL<br>-Puntero a la cadena|
|[ft_substr](https://github.com/Sant-TIG/mylibft/blob/master/strings%20functions/ft_substr.c)|Extrae una subcadena de una cadena|- Puntero a la subcadena<br>- Puntero a un caracter nulo<br>- NULL|

## Convert Functions
|FUNCIONES|DESCRIPCION|VALOR DE RETORNO|
|:-:|:-:|:-:|
|[ft_toupper](https://github.com/Sant-TIG/mylibft/blob/master/convert/ft_toupper.c)|Convierte un caracter a mayusculas|- El caracter convertido<br> - El caracter original|
|[ft_tolower](https://github.com/Sant-TIG/mylibft/blob/master/convert/ft_tolower.c)|Convierte un caracter a minusculas|- El caracter convertido<br> - El caracter original|

## Check Functions
|FUNCIONES|DESCRIPCION|VALOR DE RETORNO|
|:-:|:-:|:-:|
|[ft_islower](https://github.com/Sant-TIG/mylibft/blob/master/check/ft_islower.c)|Comprueba si un caracter esta en minusculas|- Distinto de cero<br> - Cero|
|[ft_isupper](https://github.com/Sant-TIG/mylibft/blob/master/check/ft_isupper.c)|Comprueba si un caracter esta en mayusculas|- Distinto de cero<br> - Cero|
