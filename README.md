    ███████ ██████  ███████ 
    ██      ██   ██ ██      
    █████   ██   ██ █████ 
    ██      ██   ██ ██      
    ██      ██████  ██     

# fdf

**fdf** é um projeto desenvolvido como parte do currículo da 42. O objetivo deste projeto é criar uma ferramenta de visualização de mapas 3D em wireframe, usando a biblioteca gráfica `mlx` (MiniLibX). O projeto transforma arquivos que contêm dados de elevação de um terreno em uma representação visual tridimensional.

## 📋 Índice

- [Visão Geral](#visão-geral)
- [Instalação](#instalação)
- [Uso](#uso)
- [Funcionalidades](#funcionalidades)
- [Controles](#controles)
- [Formato do Arquivo](#formato-do-arquivo)
- [Exemplos](#exemplos)
- [Contribuições](#contribuições)
- [Licença](#licença)
- [Contato](#contato)

## 🌟 Visão Geral

O **fdf** (fil de fer) é um visualizador de mapas 3D que permite carregar e visualizar mapas em perspectiva isométrica ou paralela. Ele utiliza arquivos de texto que contêm matrizes de inteiros representando alturas, e transforma esses dados em um modelo tridimensional, onde as linhas conectam os pontos baseados nos valores das alturas.

## 🚀 Instalação

### Pré-requisitos

- **gcc** (ou outro compilador C)
- **make**
- **MiniLibX** (mlx)
- **X11** (para sistemas baseados em Unix)
- **Xpm** (para manipulação de imagens XPM)

### Passos de Instalação

1. Clone o repositório:
    ```bash
    git clone https://github.com/SFzone42/fdf.git
    cd fdf
    ```

2. Compile o projeto:
    ```bash
    make
    ```

3. Execute o programa:
    ```bash
    ./fdf path/to/map.fdf
    ```

## 🎮 Uso

Para visualizar um mapa, execute o comando acima, especificando o caminho para um arquivo de mapa `.fdf`. O arquivo deve seguir o formato especificado na seção [Formato do Arquivo](#formato-do-arquivo).

## 🛠️ Funcionalidades

- **Visualização Isométrica**: Apresenta o mapa em uma projeção isométrica, dando uma perspectiva 3D.
- **Zoom e Movimento**: Permite ajustar o zoom e mover o mapa dentro da janela.
- **Rotação**: Rotacione o mapa em torno de vários eixos para visualizar de diferentes ângulos.
- **Ajuste de Altura**: Altere a escala da altura para exagerar ou suavizar as elevações.

## ⌨️ Controles

- **Teclas de seta**: Mover o mapa
- **Teclas + / -**: Zoom in / Zoom out
- **Teclas W / S**: Aumentar / diminuir a altura
- **Teclas A / D**: Rotação no eixo X
- **Teclas Q / E**: Rotação no eixo Y
- **Teclas Z / C**: Rotação no eixo Z
- **Tecla ESC**: Sair do programa

## 📂 Formato do Arquivo

O arquivo de entrada `.fdf` deve ser um arquivo de texto que contenha uma matriz de inteiros. Cada número representa a altura em um ponto específico do mapa.

Exemplo de arquivo `.fdf`:
```
0  0  0  0  0
0  1  1  1  0
0  2  2  2  0
0  1  1  1  0
0  0  0  0  0
```

## 🖼️ Exemplos

Aqui estão alguns exemplos de mapas que podem ser visualizados com o **fdf**:

1. **Mapa plano**: Um arquivo que contém apenas zeros para criar uma superfície plana.
2. **Montanha**: Arquivo com elevações que simulam uma montanha.
3. **Terreno**: Arquivo que representa um terreno variado com vales e picos.

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

## 📞 Contato

- **GitHub**: [SFzone42](https://github.com/SFzone42)
- **Email**: liedsonnhabacuc@gmail.com.com

