#include <raylib.h>
#include <iostream>
#include <string>

// Definição de cores
Color Blue = Color{52, 152, 219, 255};
Color Dark_Blue = Color{41, 128, 185, 255};
Color Light_Blue = Color{174, 214, 241, 255};
Color Orange = Color{243, 156, 18, 255};
Color White = Color{236, 240, 241, 255};

// Variáveis globais para pontuação, estado do jogo e nome do jogador
int player_score = 0;
int cpu_score = 0;
bool game_started = false;    // Indica se o jogo foi iniciado
bool game_over = false;       // Indica se o jogo terminou
std::string player_name = ""; // Armazena o nome do jogador
bool name_entered = false;    // Indica se o nome do jogador foi digitado

// Classe da bola
class Ball {
public:
    float x, y;             // Posição da bola
    int speed_x, speed_y;   // Velocidade da bola em X e Y
    int radius;             // Raio da bola

    // Função para desenhar a bola
    void Draw() {
        DrawCircle(x, y, radius, Orange);
    }

    // Função para atualizar a posição da bola e verificar colisões com as bordas
    void Update() {
        x += speed_x;
        y += speed_y;

        // Inverte a direção em Y caso a bola colida com o topo ou a base da tela
        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speed_y *= -1;
        }

        // CPU ganha ponto se a bola atravessa o lado direito da tela
        if (x + radius >= GetScreenWidth()) {
            cpu_score++;
            ResetBall();
        }

        // Jogador ganha ponto se a bola atravessa o lado esquerdo da tela
        if (x - radius <= 0) {
            player_score++;
            ResetBall();
        }
    }

    // Função para reposicionar a bola no centro e mudar a direção aleatoriamente
    void ResetBall() {
        x = GetScreenWidth() / 2;
        y = GetScreenHeight() / 2;
        int speed_choices[2] = {-1, 1};
        speed_x *= speed_choices[GetRandomValue(0, 1)];
        speed_y *= speed_choices[GetRandomValue(0, 1)];
    }
};

// Classe da raquete do jogador
class Paddle {
protected:
    // Função para limitar o movimento da raquete aos limites da tela
    void LimitMovement() {
        if (y <= 0) {
            y = 0;
        }
        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height;
        }
    }

public:
    float x, y;       // Posição da raquete
    float width, height; // Largura e altura da raquete
    int speed;        // Velocidade da raquete

    // Função para desenhar a raquete
    void Draw() {
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, White);
    }

    // Função para atualizar o movimento da raquete conforme teclas de seta
    void Update() {
        if (IsKeyDown(KEY_UP)) {
            y -= speed;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y += speed;
        }
        LimitMovement();
    }
};

// Classe da raquete do CPU, herda da classe Paddle
class CpuPaddle : public Paddle {
public:
    // Função para atualizar o movimento da raquete do CPU, seguindo a posição da bola
    void Update(int ball_y) {
        if (y + height / 2 > ball_y) {
            y -= speed;
        }
        if (y + height / 2 <= ball_y) {
            y += speed;
        }
        LimitMovement();
    }
};

// Instância das classes Ball, Paddle e CpuPaddle
Ball ball;
Paddle player;
CpuPaddle cpu;

// Função para reiniciar o jogo
void ResetGame() {
    player_score = 0;
    cpu_score = 0;
    game_over = false;
    ball.ResetBall();
}

// Função para capturar o nome do jogador
void GetPlayerName() {
    int key = GetKeyPressed();
    while (key > 0) {
        // Adiciona caracteres ao nome do jogador, limitando a 20 caracteres
        if ((key >= 32) && (key <= 125) && (player_name.size() < 20)) {
            player_name.push_back((char)key);
        }
        // Remove o último caractere se a tecla BACKSPACE for pressionada
        if (key == KEY_BACKSPACE && !player_name.empty()) {
            player_name.pop_back();
        }
        key = GetKeyPressed();
    }
}

int main() {
    // Configurações iniciais da tela
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "Pong Game");
    SetTargetFPS(60);

    // Inicialização dos parâmetros da bola e das raquetes
    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - 10;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    cpu.height = 120;
    cpu.width = 25;
    cpu.x = 10;
    cpu.y = screen_height / 2 - cpu.height / 2;
    cpu.speed = 6;

    // Loop principal do jogo
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Dark_Blue);

        if (!game_started) {
            // Tela inicial com botão "Iniciar"
            DrawText("PONG GAME", screen_width / 2 - 180, screen_height / 4, 80, Light_Blue);
            DrawText("Clique para iniciar", screen_width / 2 - 150, screen_height / 2, 40, Orange);

            Rectangle startButton = {screen_width / 2 - 100, screen_height / 2 + 80, 200, 60};
            DrawRectangleRounded(startButton, 0.5, 0, Light_Blue);
            DrawText("INICIAR", screen_width / 2 - 60, screen_height / 2 + 90, 30, Orange);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), startButton)) {
                game_started = true;
            }
        } else if (!name_entered) {
            // Entrada do nome do jogador
            DrawText("Digite seu nome:", screen_width / 2 - 180, screen_height / 4, 40, White);
            DrawText(player_name.c_str(), screen_width / 2 - 100, screen_height / 2, 30, Light_Blue);

            GetPlayerName();

            if (IsKeyPressed(KEY_ENTER) && !player_name.empty()) {
                name_entered = true;
                ResetGame();
            }
        } else if (game_over) {
            // Tela final com o resultado
            if (player_score >= 5) {
                DrawText(TextFormat("Parabéns %s, você venceu!", player_name.c_str()), screen_width / 2 - 250, screen_height / 2, 40, Orange);
            } else if (cpu_score >= 5) {
                DrawText("Você perdeu! Tente novamente!", screen_width / 2 - 200, screen_height / 2, 40, Orange);
            }

            Rectangle restartButton = {screen_width / 2 - 100, screen_height / 2 + 80, 200, 60};
            DrawRectangleRounded(restartButton, 0.5, 0, Light_Blue);
            DrawText("REINICIAR", screen_width / 2 - 75, screen_height / 2 + 90, 30, Orange);

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), restartButton)) {
                game_started = false;
                player_name.clear();
                name_entered = false;
                ResetGame();
            }
        } else {
            // Jogo em andamento
            ball.Update();
            player.Update();
            cpu.Update(ball.y);

            if (CheckCollisionCircleRec({ball.x, ball.y}, ball.radius, {player.x, player.y, player.width, player.height})) {
                ball.speed_x *= -1; // Inverte direção ao colidir com a raquete do jogador
            }
            if (CheckCollisionCircleRec({ball.x, ball.y}, ball.radius, {cpu.x, cpu.y, cpu.width, cpu.height})) {
                ball.speed_x *= -1; // Inverte direção ao colidir com a raquete do CPU
            }

            if (player_score >= 5 || cpu_score >= 5) {
                game_over = true; // Termina o jogo se algum jogador alcança 5 pontos
            }

            // Desenha a bola, as raquetes e o placar
            ball.Draw();
            player.Draw();
            cpu.Draw();
            DrawText(TextFormat("%i", player_score), screen_width / 2 + 60, 50, 40, Orange);
            DrawText(TextFormat("%i", cpu_score), screen_width / 2 - 60, 50, 40, Orange);
            DrawText(player_name.c_str(), screen_width - 150, screen_height - 30, 20, White);
        }
        EndDrawing();
    }

    // Fecha a janela do jogo
    CloseWindow();
    return 0;
}
