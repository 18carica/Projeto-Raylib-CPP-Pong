# Pong Game

Este projeto é uma implementação do clássico jogo Pong, desenvolvido em C++ utilizando a biblioteca Raylib para renderização gráfica e manipulação de entrada de usuário.

## Tabela de Conteúdos
- [Pong Game](#pong-game)
  - [Tabela de Conteúdos](#tabela-de-conteúdos)
  - [Descrição do Projeto](#descrição-do-projeto)
  - [Funcionalidades](#funcionalidades)
  - [Pré-requisitos](#pré-requisitos)
  - [Instalação](#instalação)
  - [Como Jogar](#como-jogar)
  - [Estrutura de Classes](#estrutura-de-classes)
  - [Futuras Melhorias](#futuras-melhorias)
  - [Referências](#referências)

## Descrição do Projeto
Este projeto consiste em uma versão simplificada do jogo Pong, onde o jogador controla uma raquete e enfrenta o computador (CPU). Através da Raylib, foi possível implementar gráficos e uma lógica de jogo intuitiva, incluindo detecção de colisão e um sistema básico de inteligência artificial para o oponente controlado pela máquina.

## Funcionalidades
- Controle de raquete pelo jogador
- Raquete do CPU controlada por inteligência artificial básica
- Detecção de colisões entre a bola, as raquetes e as bordas da tela
- Sistema de pontuação que define o vencedor ao alcançar 5 pontos
- Tela de início, entrada de nome do jogador e tela de "Game Over" com mensagens personalizadas

## Pré-requisitos
Para compilar e executar o jogo, é necessário:
- **C++** (compilador que suporte C++11 ou superior)
- **Raylib** (versão 3.0 ou superior)
- Sistema operacional compatível (Windows, macOS, ou Linux)

## Instalação
1. **Instale a Raylib**:
   - No Windows, você pode usar o instalador oficial ou `vcpkg`.
   - No Linux, use o comando `sudo apt install libraylib-dev`.
   - No macOS, instale via `brew install raylib`.

2. **Clone o Repositório**:
   ```bash
   git clone https://github.com/seu-usuario/pong-game.git
   cd pong-game

3. **Compile o Projeto:**
   ```bash
   g++ main.cpp -o pong -lraylib

4. **Execute o Jogo:**
   ```bash
   ./pong

## Como Jogar
- **Iniciar o Jogo**: Ao abrir o jogo, clique no botão "Iniciar".
- **Mover a Raquete**: Use as setas **↑** (para cima) e **↓** (para baixo) para mover a raquete do jogador.
- **Objetivo**: Rebata a bola para o lado do CPU e marque um ponto sempre que a bola passar pela raquete do adversário. O primeiro a alcançar 5 pontos vence a partida.
- **Reiniciar**: Ao final do jogo, você poderá clicar em "Reiniciar" para começar uma nova partida.

## Estrutura de Classes
O projeto é organizado em três classes principais:

- **Ball**: Representa a bola do jogo, controlando sua posição, velocidade e colisões com as bordas e raquetes.
- **Paddle**: Define a raquete do jogador, incluindo movimento e limites de posição na tela.
- **CpuPaddle**: Herda de `Paddle` e implementa uma inteligência artificial básica para mover a raquete do CPU em direção à bola.

## Futuras Melhorias
Algumas melhorias e funcionalidades adicionais planejadas para versões futuras:

- Adicionar níveis de dificuldade ajustáveis para o CPU
- Incluir efeitos sonoros e música de fundo
- Melhorar a interface gráfica e adicionar animações
- Implementar modo de dois jogadores

## Referências
- SANTAMARIA, Ramon. *Raylib Documentation*. Acesso em: 02 nov. 2024.
- Deitel, Harvey. *C++ Como Programar*. 5ª ed., 2006.
- Programming With Nick. *Get Started in Raylib in 20 minutes!*, YouTube Video.
- MANZANO, José Augusto Navarro Garcia. *Programação de Computadores com C++: Guia Prático de Orientação e Desenvolvimento*. 1ª ed., São Paulo: Érica, 2010.

---

Este é um projeto educacional criado com o objetivo de aprender e explorar desenvolvimento de jogos 2D em C++ utilizando a biblioteca Raylib. Aproveite o jogo e sinta-se à vontade para contribuir ou fazer sugestões!

Esse `README.md` apresenta o projeto, instruções de instalação, funcionalidades, estrutura de classes e referências, tornando-o claro e informativo para futuros desenvolvedores e usuários.
