#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

#define r1led1 D1
#define r1led2 D2
#define r1fan1 D3
#define r2led1 D4
#define r2led2 D5
#define r2fan1 D6

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("Dreamnet (( Mooazam ))", "Arham123");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  server.begin();
  pinMode(r1led1, OUTPUT);
  pinMode(r1led2, OUTPUT);
  pinMode(r1fan1, OUTPUT);
  pinMode(r2led1, OUTPUT);
  pinMode(r2led2, OUTPUT);
  pinMode(r2fan1, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  client = server.available();  //Gets a client that is connected to the server and has data available for reading.
  if (client == 1)
  {
    String request =  client.readStringUntil('\n');
    Serial.println(request);
    request.trim();
    if (request == "GET /r1led1on HTTP/1.1")
    {
      digitalWrite(r1led1, HIGH);
      Serial.println("LED 1 is ON");
    }
    if (request == "GET /r1led1off HTTP/1.1")
    {
      digitalWrite(r1led1, LOW);
      Serial.println("LED 1 is OFF");
    }
    if (request == "GET /r1led2on HTTP/1.1")
    {
      digitalWrite(r1led2, HIGH);
      Serial.println("LED 2 is ON");
    }
    if (request == "GET /r1led2off HTTP/1.1")
    {
      digitalWrite(r1led2, LOW);
      Serial.println("LED 2 is OFF");
    }
    if (request == "GET /r1fan1on HTTP/1.1")
    {
      digitalWrite(r1fan1, HIGH);
      Serial.println("FAN 1 is ON");
    }
    if (request == "GET /r1fan1off HTTP/1.1")
    {
      digitalWrite(r1fan1, LOW);
      Serial.println("FAN 1 is OFF");
    }






    if (request == "GET /r2led1on HTTP/1.1")
    {
      digitalWrite(r2led1, HIGH);
      Serial.println("LED 1 is ON");
    }
    if (request == "GET /r2led1off HTTP/1.1")
    {
      digitalWrite(r2led1, LOW);
      Serial.println("LED 1 is OFF");
    }
    if (request == "GET /r2led2on HTTP/1.1")
    {
      digitalWrite(r2led2, HIGH);
      Serial.println("LED 2 is ON");
    }
    if (request == "GET /r2led2off HTTP/1.1")
    {
      digitalWrite(r2led2, LOW);
      Serial.println("LED 2 is OFF");
    }
    if (request == "GET /r2fan1on HTTP/1.1")
    {
      digitalWrite(r2fan1, HIGH);
      Serial.println("FAN 1 is ON");
    }
    if (request == "GET /r2fan1off HTTP/1.1")
    {
      digitalWrite(r2fan1, LOW);
      Serial.println("FAN 1 is OFF");
    }
  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println("Connection: close");
  client.println("");

  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.println("<head>");
  client.println("<title>Smart Home by Mooazam</title>");
  client.println("</head>");

  client.println("<style>");
  client.println("*{text-align: center;font-family: 'Times New Roman', Times, serif; background-color: #929394;}");
  client.println("button:hover {background-color: gray;}");
  client.println("h1,h2 {color: #c7d1eb;font-size: 40px;}");
  client.println("button {color: #c7d1eb; font-size: 20px;}");
  client.println("#rooms {display: flex;align-items: center; justify-content: center;}");
  client.println("#room1, #room2 {flex: 50%; width: 50px; height: 50px;}");
  client.println("</style>");

  client.println("<body>");
  client.println("<h1>Welcome to the Smart World!</h1>");
  client.println("<div id=\"rooms\">");
  client.println("<div id=\"room1\">");
  client.println("<h2>Room 1</h2>");
  client.println("<a href=\"/r1led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/r1led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br>");
  client.println("<br>");
  client.println("<a href=\"/r1led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/r1led2off\"\"><button>LED 2 OFF</button></a>");
  client.println("<br>");
  client.println("<br>");
  client.println("<a href=\"/r1fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/r1fan1off\"\"><button>FAN 1 OFF</button></a>");
  client.println("<br>");
  client.println("<br>");
  client.println("</div>");
  
  client.println("<div id=\"room2\">");
  client.println("<h2>Room 2</h2>");
  client.println("<a href=\"/r2led1on\"\"><button>LED 1 ON</button></a>");
  client.println("<a href=\"/r2led1off\"\"><button>LED 1 OFF</button></a>");
  client.println("<br>");
  client.println("<br>");
  client.println("<a href=\"/r2led2on\"\"><button>LED 2 ON</button></a>");
  client.println("<a href=\"/r2led2off\"\"><button>LED 2 OFF</button></a>");
  client.println("<br>");
  client.println("<br>");
  client.println("<a href=\"/r2fan1on\"\"><button>FAN 1 ON</button></a>");
  client.println("<a href=\"/r2fan1off\"\"><button>FAN 1 OFF</button></a>");
  client.println("<br>");
  client.println("<br>");
  client.println("</div>");
  client.println("</div>");

  client.println("</body>");

  client.println("</html>");
}
