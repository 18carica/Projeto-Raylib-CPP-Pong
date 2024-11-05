void CpuPaddle::UpdateAI(float ball_y) {
    if (y + height / 2 < ball_y) y += speed;  // Move a raquete do CPU para baixo em direção à bola
    else if (y + height / 2 > ball_y) y -= speed; // Move a raquete do CPU para cima em direção à bola

    if (y <= 0) y = 0;                        // Limita o movimento na borda superior
    if (y + height >= GetScreenHeight())      // Limita o movimento na borda inferior
        y = GetScreenHeight() - height;
}
