void Ball::Update() {
    x += speed_x;                             // Atualiza a posição horizontal
    y += speed_y;                             // Atualiza a posição vertical

    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;                        // Inverte a direção vertical ao colidir com bordas superior/inferior
    }

    if (x + radius >= GetScreenWidth()) {
        cpu_score++;                          // Incrementa a pontuação do CPU
        ResetBall();                          // Reseta a posição da bola
    }

    if (x - radius <= 0) {
        player_score++;                       // Incrementa a pontuação do jogador
        ResetBall();                          // Reseta a posição da bola
    }
}
