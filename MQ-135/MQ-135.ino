// --- ESP32 讀取 MQ135 AO (類比輸出) 程式碼 ---

// 1. 定義腳位
const int mq135_AO_Pin = 32; // 將 MQ135 的 AO 連接到 ESP32 的 GPIO 32
const int threshold = 1000;  // 自訂的警告閾值 (範圍 0~4095，請依實際環境調整)

void setup() {
  // 初始化序列埠通訊，鮑率設定為 115200 (ESP32 的標準鮑率)
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("==================================");
  Serial.println("MQ135 類比訊號讀取系統啟動...");
  Serial.println("==================================");
}

void loop() {
  // 2. 多次讀取求平均值 (減少感測器數值跳動造成的誤差)
  long sum = 0;
  int sampleCount = 10; // 連續讀取 10 次

  for(int i = 0; i < sampleCount; i++) {
    sum += analogRead(mq135_AO_Pin); // 讀取類比值並累加
    delay(10);                       // 每次讀取間隔 10 毫秒
  }

  int averageValue = sum / sampleCount; // 計算平均值

  // 3. 將結果印出到序列埠監控視窗
  Serial.print("空氣品質原始數值 (AO): ");
  Serial.print(averageValue);

  // 4. 軟體判斷 (這段邏輯完全取代了 DO 腳位的功能)
  if (averageValue > threshold) {
    Serial.println("  --> [⚠️ 警告] 氣體濃度偏高！");
    // 您可以在這裡加入後續動作：例如驅動蜂鳴器、發送 LINE 通知或 MQTT 訊息
  } else {
    Serial.println("  --> [✅ 正常] 空氣品質良好。");
  }

  // 5. 延遲 1 秒後進行下一次測量
  delay(1000); 
}