# PIPEX

## Visão Geral

Pipex é um projeto desenvolvido em C para manipulação de pipes, que visa replicar o comportamento de um pipeline do shell. O programa redireciona dados de um arquivo de entrada através de uma sequência de comandos e salva o resultado em um arquivo de saída especificado.

O Pipex executa comandos do shell criando uma cadeia entre eles, permitindo que o resultado de um comando seja usado como entrada para o próximo, de forma semelhante aos pipes (|) do shell. Este projeto é executado com quatro argumentos, descritos a seguir.

## Uso

**Compilação**

Para compilar o programa, execute o seguinte comando:

- `make`

O Makefile inclui as seguintes regras:

- `all` - compila o programa.
- `clean` - remove os arquivos objeto.
- `fclean` - remove os arquivos objeto e o executável.
- `re` - recompila o projeto executando fclean seguido de all.

## Execução

A sintaxe para executar o programa é:

```
./pipex file1 cmd1 cmd2 file2
```

- `file1`: Nome do arquivo de entrada.
- `cmd1`: Primeiro comando do shell com seus argumentos.
- `cmd2`: Segundo comando do shell com seus argumentos.
- `file2`: Nome do arquivo de saída.

O Pipex lerá dados do file1, executará o cmd1, enviará o resultado para o cmd2 e gravará a saída final no file2.

## Exemplos

**Exemplo 1**

```
./pipex infile "ls -l" "wc -l" outfile
```

Comando equivalente no shell: `< infile ls -l | wc -l > outfile`

**Exemplo 2**
```
./pipex infile "grep a1" "wc -w" outfile
```

Comando equivalente no shell: `< infile grep a1 | wc -w > outfile`

## Requisitos

Para garantir o funcionamento correto e a estabilidade, o projeto deve seguir os requisitos abaixo:

- **Tratamento de Erros**: Todos os erros devem ser tratados para evitar que o programa saia inesperadamente devido a problemas como falhas de segmentação, erros de acesso à memória ou vazamentos de memória.
- **Gestão de Memória**: O programa deve gerenciar a memória de forma eficiente, evitando vazamentos.
- **Comportamento dos Comandos**: O programa deve replicar o comportamento de um pipeline do shell, tratando erros da mesma forma que um shell ao executar o comando `< file1 cmd1 | cmd2 > file2`.

## Funções Permitidas

O Pipex utiliza apenas as seguintes funções da biblioteca padrão e chamadas de sistema:

- Operações de arquivo: `open`, `close`, `read`, `write`.
- Gestão de memória: `malloc`, `free`.
- Tratamento de erros: `perror`, `strerror`.
- Manipulação de arquivos e processos: `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`.
- Também é permitido o uso de *ft_printf* ou uma implementação equivalente criada por você, assim como funções da sua biblioteca *libft*.

