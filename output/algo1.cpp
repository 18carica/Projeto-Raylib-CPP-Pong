while (!WindowShouldClose()) {                // Loop principal do jogo
    BeginDrawing();                           // Início do desenho
    ClearBackground(Dark_Blue);               // Define a cor de fundo

    if (!game_started) {                      // Verifica se o jogo foi iniciado
        // Exibe a tela inicial e verifica clique para iniciar o jogo
    } else if (!name_entered) {               // Verifica se o nome foi inserido
        // Entrada do nome do jogador e exibição
    } else if (game_over) {                   // Verifica se o jogo terminou
        // Exibe a tela de Game Over e verifica se o jogador quer reiniciar
    } else {
        // Atualiza as posições da bola e das raquetes
        ball.Update();
        player.Update();
        cpu.UpdateAI(ball.y);                 // Atualiza a posição do CPU com base na bola

        // Verifica colisões e desenha todos os elementos
    }

    EndDrawing();                             // Fim do desenho
}
