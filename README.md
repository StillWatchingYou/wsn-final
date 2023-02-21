# wsn-final

Trong qua trình học môn WSN, chúng tôi đã tạo ra 1 dự án với mô hình như sau: 
- 2 node điều khiển với cấu hình là: 
    + 1 cặp pin lithium, 
    +1 mạch sạc typeC
    + 1 ổn áp
    + 1 Vi xử lý ESP32
    + 1 cảm biến nhiệt độ DS18B20
    + 1 led báo hiệu 
    + và 1 số điện trở
- 2 node cảm biến này thực hiện truyền dữ liệu tới Broker Node-red bằng giao thức MQTT
- Broker này sẽ truyển dữ liệu tới Thingspeak bằng giao thức http
- Thingspeak sẽ chịu trách nhiệm hiển thị và xuất dữ liệu dưới dạng file Excel



- Về ESP32:
Trong file github này chúng tôi cung cấp file lập trình cho cặp vi xử lý ESP32(esp-nodered-send1 và esp-noidered-send2)
Bằng cách setup hệ thống với mô hình phù hợp như trên. Người dùng tiến hành thay đổi 1 vài thông tin như ssid,password của Wifi, Địa chỉ IP sau đó tải code vào ESP32 là hoàn thành việc setup node cảm biển

Về Node-red:
- Các bạn có thể tìm hiểu về node-red tại đây: https://nodered.org/
- Các bạn setup như hình "setup-nodered.png" tôi có đính kèm bên dưới

Về Thingspeak:
- Các bạn có thể tìm hiểu tại đây: "https://thingspeak.com/", "http://iottuonglai.com/thinkspeak-la-gi.html"
- Setup API key phù hợp để thực hiện dự án giống như của chúng tôi

Chúc các bạn thành công.