# Pong Game

Este projeto é uma implementação do clássico jogo Pong, desenvolvido em C++ utilizando a biblioteca Raylib para renderização gráfica e manipulação de entrada de usuário.

## Tabela de Conteúdos
1. [Descrição do Projeto](#descrição-do-projeto)
2. [Funcionalidades](#funcionalidades)
3. [Pré-requisitos](#pré-requisitos)
4. [Instalação](#instalação)
5. [Como Jogar](#como-jogar)
6. [Estrutura de Classes](#estrutura-de-classes)
7. [Futuras Melhorias](#futuras-melhorias)
8. [Referências](#referências)

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
