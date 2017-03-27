var gameStart = false;

var lens = {
  x: 2000,
  y: 400,
  diam: 25,
  speedX: 5,
  speedY: 5,
};

var lensPosX = 2000;
var speedX = 5;
var speedY = 5;
var sensorY = 400;
var sensorX = 1000;
var delayMillis = 1000;
var tempX = 5;
var tempY = 5;
var reset = 0;
var speedCounter = 0;
var resetCounter = 0;
var reset2 = 0;

var s = "Mount a Lens on the Camera! Move the lens with your arrow keys";

function setup(){
  createCanvas(1200, 860);
  smooth();

}

function draw(){
  gameStart == true;

  background(0,0,0);
  noStroke;
  createCamera();
  createLens();
  lensBounceTopAndBottom();
  lensMount();
  //showScore();
  if(lens.x > 1300){
  sensorY = random(100,700);
  speedX += 1;
  lens.y = 400;
  }
  writeRules();

}

function createCamera(){
  stroke(255,255,255);

  line(sensorX, sensorY, sensorX, sensorY-10);
  line(sensorX, sensorY, sensorX, sensorY+10);
  line(sensorX, sensorY-10, sensorX+10, sensorY-10);
  line(sensorX, sensorY+10, sensorX+10,sensorY+10);
  line(sensorX+10, sensorY-10, sensorX+10, sensorY-30);
  line(sensorX+10, sensorY-10, sensorX+10, sensorY+30);
  line(sensorX+10, sensorY-30, sensorX+120, sensorY-30);
  line(sensorX+10, sensorY+30, sensorX+120, sensorY+30);
  line(sensorX+120, sensorY-30, sensorX+120, sensorY+30);

  //tripod
  line(sensorX+60, sensorY+30, sensorX+40, sensorY+120);
  line(sensorX+70, sensorY+30, sensorX+70, sensorY+120);
  line(sensorX+80, sensorY+30, sensorX+100, sensorY+120);

  //logo
  line(sensorX+35+13, sensorY - 12, sensorX+20+13, sensorY + 12);
  line(sensorX+35+13, sensorY - 12, sensorX+35+13, sensorY + 12);
  line(sensorX+25+13, sensorY+5, sensorX+35+13, sensorY+5);

  line(sensorX+42+13, sensorY - 12, sensorX + 42+13, sensorY +12);
  line(sensorX+42+13, sensorY, sensorX+52+13, sensorY+12);
  line(sensorX+42+13, sensorY-12, sensorX+48+13,sensorY-12);
  line(sensorX+42+13, sensorY, sensorX+48+13,sensorY);
  line(sensorX+48+13, sensorY-12, sensorX+52+13, sensorY-5);
  line(sensorX+48+13, sensorY, sensorX+52+13, sensorY-5);

  line(sensorX+42+13+13, sensorY - 12, sensorX + 42+13+13, sensorY +12);
  line(sensorX+42+13+13, sensorY, sensorX+52+13+13, sensorY+12);
  line(sensorX+42+13+13, sensorY-12, sensorX+48+13+13,sensorY-12);
  line(sensorX+42+13+13, sensorY, sensorX+48+13+13,sensorY);
  line(sensorX+48+13+13, sensorY-12, sensorX+52+13+13, sensorY-5);
  line(sensorX+48+13+13, sensorY, sensorX+52+13+13, sensorY-5);

  line(sensorX+70+13, sensorY - 12, sensorX+70+13, sensorY +12);

}

function writeRules(){
  noStroke();
 fill(0,0,0);
 rect(0,790,1200,70);
 fill(255,255,255);
 textSize(20);
  text("Mount the Lens!", 530, 810);
  textSize(17);
 text("Control: Use Up Arrow and Down Arrow", 460, 840);
}

function createLens(){
  if(lens.x > 1300){
    lens.x = 50;
  }
  if(resetCounter > 400 && reset2 == 1){
    speedX = speedX + 80;
    speedY = 12;
    reset2 = 0;
  }
  else if(resetCounter > 320 && reest2 == 1){
    speedX = speedX + 32;
    speedY = 10;
    reset2 = 0;
  }
  else if(resetCounter > 250 && reset2 == 1){
    speedX = speedX + 16;
    speedY = 8;
    reset2 = 0;
  }
  else if(resetCounter > 200 && reset2 == 1){
    speedX = speedX + 12;
    speedY = 6;
    reset2 = 0;
  }
  else if(resetCounter > 150 && reset2 == 1){
    speedX = speedX + 8;
    reset2 = 0;
  }
  else if(resetCounter > 100 && reset2 == 1){
    speedX = speedX + 4;
    reset2 = 0;
  }
  else if(resetCounter > 50 && reset2 == 1){
    speedX = speedX + 2;
    reset2 = 0;
  }

  stroke(255, 255, 255); //draw a lens
  line(lens.x, lens.y, lens.x, lens.y - 30);
  line(lens.x, lens.y, lens.x, lens.y + 30);
  line(lens.x, lens.y - 30, lens.x + 10, lens.y - 30);
  line(lens.x, lens.y + 30, lens.x + 10, lens.y + 30);
  line(lens.x + 10, lens.y - 30, lens.x + 20, lens.y - 30);
  line(lens.x + 10, lens.y + 30, lens.x + 20, lens.y + 30);
  line(lens.x + 20, lens.y - 30, lens.x + 50, lens.y - 5);
  line(lens.x + 20, lens.y + 30, lens.x + 50, lens.y + 5);
  line(lens.x + 50, lens.y - 5, lens.x + 50, lens.y + 5); //where lens mounts

  line(lens.x + 10, lens.y - 30, lens.x + 10, lens.y + 30);


  //ellipse(lens.x, lens.y, lens.diam, lens.diam);

    lens.x = lens.x + speedX;

  if(keyIsDown(DOWN_ARROW) == true){
    lens.y = lens.y + speedY;
  }
  if(keyIsDown(UP_ARROW) == true){
    lens.y = lens.y - speedY;
  }

}

function lensBounceTopAndBottom(){

    //If if the lens hits the top or bottom of the court it bounces
    if (lens.y + 12.5 > height || lens.y < 12.5 && lens.x > 0 && lens.x < width && lens.y > 0 && lens.y < height) {

    showScore();

    }

}

function lensMount(){
  if (lens.x + 50 == sensorX && lens.y - 5 > sensorY - 12 && lens.y + 5 < sensorY + 12) {
  speedX = 0;
  //speedCounter += 0.01;
  for(var i = 0; i < 20; i += 1){
     textSize(50);
     for(var u = 0; u < 15; u += 1){
       fill(random(255),random(255),random(255));
    text("Mounted!", 250*u + i*50 - 600, 50*i+80);
     }
  }
  setTimeout(function() {
    reset = 1;
    resetCounter += 1;
  }, delayMillis);

  }

  if(reset == 1){
    lens.x = 50;
    speedX = 5;
    reset = 0;
    reset2 = 1;
    sensorY = random(100,700);
    lens.y = 400;

  }



}
