#include <unistd.h>
#include <fcntl.h>

//referencias
//http://pubs.opengroup.org/onlinepubs/7908799/xsh/fcntl.h.html - fcntl.h
//http://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html - unistd.h
//http://pubs.opengroup.org/onlinepubs/9699919799/ - refencia padrão
//http://man7.org/linux/man-pages/man2/open.2.html - open
//https://en.wikipedia.org/wiki/File_descriptor - descritor de arquivo

int main()
{
	char buffer[100];
	int origem,destino;

	/*
		int open(const char *buffer, int oflag)

		@param (const char *buffer, int oflag)  verifica no diretorio se há ocorrência do arquivo 
		contido na variavel buffer, e dependendo da flag ele abre apenas para leitura(O_RDONLY), 
		escrita(O_WRONLY), ou ambos(O_RDWR), e um terceiro parametro opcional o qual determina
		os previlegios do arquivo, como apenas leitura , apenas escrita, etc.

 		@return (int) retorna um inteiro descritor do arquivo caso encontrado, ou retorna -1 em 
 		caso de erro ao não encontrar 

		-----------------------------------------------------------------------------------------

		ssize_t write(int action , const void *buffer , size_t count)

		@param (int action , const void *buffer , size_t nbytes) 
			int action - 0 para Input , 1 para Output e 2 para error
			buffer - cadeia de caracteres 
			count - tamanho da cadeia (buffer) a ser impressa

		@return (ssize_t) em caso de sucesso o numero de bytes escritos é retornado ou 
		zero indicando que nada foi escrito
	*/

	if( (origem = open("origem.txt",O_RDONLY) ) < 0 ){
		write(1,"Arquivo de origem nao existe\n",30);
		return 0;
	}


	/*
		outras flags para open

		O_CREAT = cria o arquivo caso nao exista
		O_EXCL = nao permite recriar o arquivo -> flag exclusiva
		permissões -> 0640,0644,0755,0777
	*/

	if( (destino = open("destino.txt",O_CREAT | O_EXCL | O_WRONLY,0777) ) < 0 ){
		write(1,"Arquivo jah existe!\n",21);
		return 0;
	}

	/*
		ssize_t read(int fildes, void *buf, size_t nbyte)
		
		@param (int fildes, void *buffer, size_t nbyte)
			fildes - valor inteiro descritor do arquivo , o qual pode ser obtido
			por exemplo atraves da função open
			buffer - é usado para guardar o numero de bytes lidos pelo terceiro 
			parametro
			nbyte - numero de bytes a ser lido 

		@return (ssize_t) Se read() é interrompida por um sinal antes que leia todos os 
		dados, ela deve retornar -1 com errno definido. Se read() é interrompida 
		por um sinal após ter lido com sucesso alguns dados, ele deve retornar 
		o número de bytes lidos.
	*/

	ssize_t copy;
	while( copy = read(origem,buffer,100) )
		write(destino,buffer,copy);

	close(origem);
	close(destino);

	write(1,"arquivo copiado com sucesso!\n",30);


	return 0;
}
