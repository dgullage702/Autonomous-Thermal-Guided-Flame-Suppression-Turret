#include <Wire.h>
#include <Adafruit_MLX90640.h>

Adafruit_MLX90640 mlx;
float frame[32 * 24];

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);
  Wire.setClock(400000);
  if (!mlx.begin(MLX90640_I2CADDR_DEFAULT, &Wire)) {
    Serial.println("MLX90640 not found");
    while (1) delay(10);
  }
  mlx.setMode(MLX90640_CHESS);
  mlx.setResolution(MLX90640_ADC_18BIT);
  mlx.setRefreshRate(MLX90640_4_HZ);
}

void loop() {
  if (mlx.getFrame(frame) != 0) return;
  int hotIndex = 0;
  for (int i = 1; i < 32 * 24; i++) {
    if (frame[i] > frame[hotIndex]) hotIndex = i;
  }
  int x = hotIndex % 32;
  int y = hotIndex / 32;
  Serial.print("hot ");
  Serial.print(frame[hotIndex]);
  Serial.print("  x ");
  Serial.print(x);
  Serial.print("  y ");
  Serial.println(y);
}
