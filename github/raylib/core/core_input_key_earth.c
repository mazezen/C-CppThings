//--------------------------------------------------------------------------------
// eval cc core_input_key_earth.c $(pkg-config --libs --cflags raylib) -o core_input_key_earth.out
// clang core_input_key_earth.c $(pkg-config --libs --cflags raylib) -o core_input_key_earth.out
//--------------------------------------------------------------------------------
#include "raylib.h"

// Draw a more natural landmass with multiple random-like overlapping circles
static void DrawLandmass(Image *image, int points[][2], int count, int radius, Color color)
{
    for (int i = 0; i < count; i++)
    {
        ImageDrawCircle(image, points[i][0], points[i][1], radius, color);
        // Add some variation with smaller overlapping circles
        ImageDrawCircle(image, points[i][0] - radius / 2, points[i][1] - radius / 3, radius / 2, color);
        ImageDrawCircle(image, points[i][0] + radius / 3, points[i][1] + radius / 4, radius / 3, color);
    }
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - input keys earth");

    // Define the camera
    Camera3D camera = {0};
    camera.position = (Vector3){2.5f, 0.5f, 2.5f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Generate procedural earth texture (equirectangular projection)
    int texW = 512;
    int texH = 256;
    Color oceanColor = (Color){25, 85, 170, 255};
    Color oceanShallow = (Color){35, 105, 190, 255};
    Image earthImage = GenImageColor(texW, texH, oceanColor);

    // Add shallow ocean areas near continents
    for (int y = 0; y < texH; y++)
    {
        for (int x = 0; x < texW; x += 2)
        {
            if ((x * 7 + y * 13) % 100 < 8)
                ImageDrawPixel(&earthImage, x, y, oceanShallow);
        }
    }

    // --- Draw Continents ---

    // Color palette
    Color greenForest = (Color){45, 130, 55, 255};
    Color greenLight = (Color){65, 155, 65, 255};
    Color greenDark = (Color){30, 100, 40, 255};
    Color brown = (Color){160, 130, 60, 255};
    Color brownDark = (Color){130, 100, 45, 255};
    Color sand = (Color){195, 175, 100, 255};
    Color whiteIce = (Color){225, 230, 240, 255};

    // --- North America ---
    int naPoints[][2] = {
        {105, 52},
        {115, 48},
        {120, 55},
        {110, 60},
        {100, 58},
        {95, 65},
        {108, 70},
        {118, 68},
        {125, 62},
        {130, 58},
        {128, 50},
        {122, 45},
        {112, 42},
        {105, 45},
        // Florida/Caribbean
        {110, 82},
        {120, 85},
        // Alaska/North
        {85, 40},
        {90, 38},
        {95, 42},
        // Mexico/Central America
        {100, 78},
        {92, 85},
        {105, 90},
        {115, 90},
        {95, 75},
        {105, 80},
        // Greenland
        {140, 30},
        {148, 32},
        {152, 38},
        {145, 42},
        {138, 38},
        {135, 32},
    };
    DrawLandmass(&earthImage, naPoints, sizeof(naPoints) / sizeof(naPoints[0]), 12, greenForest);
    DrawLandmass(&earthImage, naPoints, sizeof(naPoints) / sizeof(naPoints[0]), 8, greenLight);
    // Desert/southwest
    int naDesert[][2] = {{104, 68}, {112, 65}, {118, 68}, {108, 72}};
    DrawLandmass(&earthImage, naDesert, sizeof(naDesert) / sizeof(naDesert[0]), 6, brown);

    // --- South America ---
    int saPoints[][2] = {
        {148, 105},
        {155, 100},
        {162, 102},
        {168, 108},
        {172, 115},
        {175, 125},
        {176, 135},
        {174, 145},
        {170, 155},
        {165, 162},
        {158, 165},
        {152, 160},
        {148, 152},
        {145, 142},
        {144, 132},
        {145, 122},
        {146, 112},
        // Brazil
        {165, 115},
        {175, 118},
        {180, 125},
        {182, 135},
        {178, 142},
        {170, 140},
        {162, 135},
        {160, 125},
        // Chile/Argentina
        {155, 150},
        {160, 155},
        {162, 160},
        {158, 162},
        {152, 158},
        {150, 150},
        {148, 142},
        // Colombia/Venezuela
        {155, 105},
        {162, 105},
        {165, 108},
        {160, 110},
        {152, 108},
    };
    DrawLandmass(&earthImage, saPoints, sizeof(saPoints) / sizeof(saPoints[0]), 10, greenForest);
    DrawLandmass(&earthImage, saPoints, sizeof(saPoints) / sizeof(saPoints[0]), 7, greenDark);

    // Amazon darker green
    int amazon[][2] = {{168, 118}, {175, 120}, {178, 128}, {170, 130}, {165, 125}};
    DrawLandmass(&earthImage, amazon, sizeof(amazon) / sizeof(amazon[0]), 8, greenDark);

    // Andes brown
    int andes[][2] = {{152, 125}, {154, 135}, {155, 145}, {156, 155}, {158, 148}, {156, 138}, {154, 128}};
    DrawLandmass(&earthImage, andes, sizeof(andes) / sizeof(andes[0]), 4, brown);

    // --- Europe ---
    int euPoints[][2] = {
        {248, 42},
        {255, 38},
        {262, 36},
        {270, 38},
        {278, 40},
        {285, 42},
        {290, 48},
        {288, 55},
        {282, 58},
        {275, 56},
        {268, 54},
        {260, 52},
        {252, 50},
        {248, 46},
        // British Isles
        {242, 44},
        {245, 48},
        // Scandinavia
        {258, 25},
        {265, 22},
        {272, 25},
        {275, 30},
        {270, 35},
        {262, 32},
        {256, 30},
        // Iberian Peninsula
        {245, 55},
        {252, 56},
        {258, 58},
        {255, 62},
        {248, 60},
        // Italy
        {260, 58},
        {264, 62},
        {266, 65},
        {262, 64},
        {258, 60},
        // Balkans
        {272, 55},
        {278, 56},
        {282, 60},
        {280, 64},
        {274, 60},
    };
    DrawLandmass(&earthImage, euPoints, sizeof(euPoints) / sizeof(euPoints[0]), 9, greenLight);
    DrawLandmass(&earthImage, euPoints, sizeof(euPoints) / sizeof(euPoints[0]), 6, greenForest);

    // --- Africa ---
    int afPoints[][2] = {
        {260, 82},
        {268, 78},
        {278, 76},
        {288, 78},
        {295, 82},
        {300, 90},
        {302, 100},
        {300, 110},
        {296, 120},
        {290, 128},
        {282, 132},
        {274, 130},
        {268, 125},
        {262, 118},
        {258, 108},
        {255, 98},
        {254, 90},
        {256, 84},
        // West Africa
        {250, 88},
        {248, 95},
        {252, 100},
        {258, 98},
        {256, 90},
        // Horn of Africa
        {300, 95},
        {305, 100},
        {308, 105},
        {305, 108},
        {300, 105},
        {298, 98},
        // Southern Africa
        {278, 128},
        {284, 130},
        {290, 132},
        {292, 138},
        {288, 142},
        {282, 140},
        {276, 135},
        {274, 130},
        // Madagascar
        {306, 118},
        {310, 122},
        {312, 128},
        {308, 132},
        {304, 126},
    };
    DrawLandmass(&earthImage, afPoints, sizeof(afPoints) / sizeof(afPoints[0]), 10, greenForest);
    DrawLandmass(&earthImage, afPoints, sizeof(afPoints) / sizeof(afPoints[0]), 7, greenLight);

    // Sahara desert
    int sahara[][2] = {{260, 85}, {270, 82}, {280, 80}, {290, 84}, {295, 88}, {290, 92}, {280, 90}, {270, 88}, {262, 88}};
    DrawLandmass(&earthImage, sahara, sizeof(sahara) / sizeof(sahara[0]), 8, sand);
    DrawLandmass(&earthImage, sahara, sizeof(sahara) / sizeof(sahara[0]), 5, brown);

    // Kalahari
    int kalahari[][2] = {{270, 125}, {278, 126}, {284, 128}, {280, 132}, {272, 130}};
    DrawLandmass(&earthImage, kalahari, sizeof(kalahari) / sizeof(kalahari[0]), 6, sand);

    // --- Asia ---
    int asiaPoints[][2] = {
        {290, 40},
        {300, 35},
        {310, 30},
        {320, 28},
        {335, 26},
        {350, 25},
        {365, 28},
        {375, 32},
        {380, 38},
        {385, 45},
        {382, 52},
        {375, 55},
        {365, 52},
        {355, 48},
        {345, 45},
        {335, 44},
        {325, 42},
        {315, 40},
        {305, 38},
        {295, 38},
        // India
        {340, 58},
        {345, 55},
        {352, 56},
        {358, 62},
        {356, 70},
        {350, 72},
        {344, 68},
        {340, 62},
        // Southeast Asia
        {365, 60},
        {372, 62},
        {378, 65},
        {382, 70},
        {380, 75},
        {375, 72},
        {368, 68},
        {362, 64},
        // Indonesia / Archipelago
        {370, 80},
        {378, 82},
        {385, 84},
        {390, 86},
        {395, 84},
        {388, 80},
        {380, 78},
        {392, 82},
        {400, 84},
        {405, 86},
        {398, 88},
        {392, 86},
        // Japan
        {390, 30},
        {394, 34},
        {396, 40},
        {392, 44},
        {388, 38},
        // Korea
        {382, 45},
        {386, 48},
        {384, 52},
        {380, 48},
        // Kamchatka / NE Russia
        {390, 15},
        {395, 18},
        {398, 22},
        {394, 26},
        {388, 22},
        {392, 12},
        {396, 15},
        // Siberia
        {310, 18},
        {325, 15},
        {340, 14},
        {355, 12},
        {370, 14},
        {380, 18},
        {385, 22},
        {378, 24},
        {365, 22},
        {350, 20},
        {335, 18},
        {320, 18},
        {310, 20},
        // Middle East / Arabian Peninsula
        {310, 55},
        {318, 54},
        {325, 56},
        {330, 62},
        {328, 68},
        {322, 70},
        {315, 66},
        {310, 60},
    };
    DrawLandmass(&earthImage, asiaPoints, sizeof(asiaPoints) / sizeof(asiaPoints[0]), 10, greenForest);
    DrawLandmass(&earthImage, asiaPoints, sizeof(asiaPoints) / sizeof(asiaPoints[0]), 7, greenLight);

    // Gobi / Central Asia deserts
    int gobi[][2] = {{330, 32}, {340, 30}, {350, 30}, {360, 32}, {355, 36}, {345, 36}, {335, 36}, {328, 34}};
    DrawLandmass(&earthImage, gobi, sizeof(gobi) / sizeof(gobi[0]), 7, sand);

    // Arabian desert
    int arabian[][2] = {{312, 58}, {320, 56}, {326, 60}, {324, 66}, {316, 64}, {310, 60}};
    DrawLandmass(&earthImage, arabian, sizeof(arabian) / sizeof(arabian[0]), 6, sand);

    // Himalayas (brown)
    int himalayas[][2] = {{335, 52}, {345, 50}, {355, 52}, {360, 55}, {350, 56}, {340, 54}};
    DrawLandmass(&earthImage, himalayas, sizeof(himalayas) / sizeof(himalayas[0]), 5, brown);

    // --- Australia ---
    int auPoints[][2] = {
        {435, 140},
        {442, 136},
        {450, 138},
        {458, 142},
        {462, 148},
        {460, 155},
        {455, 160},
        {448, 162},
        {440, 158},
        {435, 152},
        {433, 146},
        // Tasmania
        {442, 168},
        {446, 172},
        // New Zealand
        {478, 150},
        {482, 156},
        {484, 162},
        {480, 166},
        {476, 158},
        // New Guinea
        {405, 82},
        {410, 80},
        {415, 82},
        {412, 86},
        {406, 85},
    };
    DrawLandmass(&earthImage, auPoints, sizeof(auPoints) / sizeof(auPoints[0]), 8, brown);
    DrawLandmass(&earthImage, auPoints, sizeof(auPoints) / sizeof(auPoints[0]), 5, sand);
    // Australia east coast green
    int auGreen[][2] = {{448, 140}, {455, 142}, {460, 146}, {455, 150}, {448, 148}};
    DrawLandmass(&earthImage, auGreen, sizeof(auGreen) / sizeof(auGreen[0]), 6, greenLight);

    // --- Antarctica ---
    for (int x = 0; x < texW; x++)
    {
        for (int y = texH - 20; y < texH; y++)
        {
            if ((x * 3 + y * 7) % 13 > 5)
                ImageDrawPixel(&earthImage, x, y, whiteIce);
        }
    }

    // --- Arctic ice ---
    for (int x = 0; x < texW; x++)
    {
        for (int y = 0; y < 12; y++)
        {
            if ((x * 5 + y * 11) % 15 > 5)
                ImageDrawPixel(&earthImage, x, y, whiteIce);
        }
    }

    // Add some cloud-like white patches scattered around
    for (int i = 0; i < 30; i++)
    {
        int cx = (i * 137 + 50) % texW;
        int cy = 20 + (i * 89 + 30) % (texH - 50);
        int r = 5 + (i * 17) % 15;
        Color cloudColor = (Color){230, 235, 245, 200};
        ImageDrawCircle(&earthImage, cx, cy, r, cloudColor);
        ImageDrawCircle(&earthImage, cx + 3, cy + 2, r - 2, cloudColor);
        ImageDrawCircle(&earthImage, cx - 2, cy + 1, r - 3, (Color){240, 245, 255, 180});
    }

    // Load texture from the generated image
    Texture2D earthTexture = LoadTextureFromImage(earthImage);
    UnloadImage(earthImage);

    // Generate sphere mesh and model
    Mesh sphereMesh = GenMeshSphere(1.0f, 48, 48);
    Model sphereModel = LoadModelFromMesh(sphereMesh);
    sphereModel.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = earthTexture;

    // Initial state
    float rotationAngle = 0.0f;
    float rotationSpeed = 0.3f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Keyboard controls
        if (IsKeyDown(KEY_RIGHT))
            rotationSpeed += 0.1f;
        if (IsKeyDown(KEY_LEFT))
            rotationSpeed -= 0.1f;
        if (IsKeyDown(KEY_UP))
            rotationSpeed += 0.05f;
        if (IsKeyDown(KEY_DOWN))
            rotationSpeed -= 0.05f;
        if (IsKeyPressed(KEY_SPACE))
            rotationSpeed = 0.0f;
        if (IsKeyPressed(KEY_ENTER))
            rotationSpeed = 0.3f;

        // Clamp speed
        if (rotationSpeed > 5.0f)
            rotationSpeed = 5.0f;
        if (rotationSpeed < -5.0f)
            rotationSpeed = -5.0f;

        // Auto-rotate
        rotationAngle += rotationSpeed;

        // Camera orbit with mouse
        UpdateCamera(&camera, CAMERA_ORBITAL);

        BeginDrawing();
        ClearBackground((Color){10, 10, 30, 255}); // Dark space-like background

        BeginMode3D(camera);

        // Draw the globe with rotation
        DrawModelEx(sphereModel, (Vector3){0.0f, 0.0f, 0.0f},
                    (Vector3){0.0f, 1.0f, 0.0f}, rotationAngle,
                    (Vector3){1.0f, 1.0f, 1.0f}, WHITE);

        // Draw wireframe overlay for a subtle outline effect
        DrawSphereWires((Vector3){0.0f, 0.0f, 0.0f}, 1.01f, 24, 24, (Color){100, 150, 220, 60});

        EndMode3D();

        // Draw UI overlay
        DrawText("GLOBE", screenWidth / 2 - MeasureText("GLOBE", 40) / 2, 15, 40, (Color){200, 220, 255, 200});
        DrawText("LEFT/RIGHT: adjust speed | UP/DOWN: fine-tune", 10, screenHeight - 60, 16, (Color){180, 190, 210, 180});
        DrawText("SPACE: stop | ENTER: reset | Mouse: orbit camera", 10, screenHeight - 35, 16, (Color){180, 190, 210, 180});
        DrawText(TextFormat("Rotation: %.1f deg | Speed: %.2f", rotationAngle, rotationSpeed), 10, screenHeight - 85, 16, (Color){180, 190, 210, 180});

        EndDrawing();
    }

    // Cleanup
    UnloadTexture(earthTexture);
    UnloadModel(sphereModel);
    CloseWindow();

    return 0;
}
