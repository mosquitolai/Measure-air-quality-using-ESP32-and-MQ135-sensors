# 中文簡介：

本程式使用 ESP32 讀取 MQ135 空氣品質感測器的類比輸出（AO），並透過 analogRead() 取得 0–4095 範圍的數值。為了降低感測雜訊影響，程式會連續取樣 10 次並計算平均值，作為最終讀數。系統會將即時空氣品質數據輸出至序列埠監控視窗，並依照設定的閾值（threshold）進行判斷：當數值超過門檻時，顯示氣體濃度偏高的警告；反之則顯示空氣品質正常。本程式可作為後續擴充的基礎，例如加入蜂鳴器警報、Wi-Fi 傳輸或物聯網通知功能。

-----------------------------------------------------------------------------------------------------------------------------------------------

# English Description:

This program uses an ESP32 to read the analog output (AO) from an MQ135 air quality sensor via the analogRead() function, producing values ranging from 0 to 4095. To reduce sensor noise, the system takes 10 consecutive samples and calculates their average as the final reading. The measured air quality data is displayed on the serial monitor in real time. Based on a predefined threshold value, the system determines whether the gas concentration is high or within a normal range. When the reading exceeds the threshold, a warning message is printed; otherwise, the air quality is considered normal. This program can be further extended to include features such as buzzer alerts, Wi-Fi transmission, or IoT-based notifications.
