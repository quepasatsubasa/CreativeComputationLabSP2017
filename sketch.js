var x = 0;
var speed = 2;
var direction = 1;

var r = 250;
var g = 0;
var b = 0;

function setup() {
  createCanvas(400,400);
  background(250,250,250)
}


function draw() {
  background(250,250,250);
  stroke(255);
  strokeWeight(4);
  fill(r,g,b);
  ellipse(x,200,100,100);
  
  if(direction == 1){
     x = x + direction*speed;
  } 
  
  if (x > width){
    direction = -1
    speed++
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);
  }
  
  
 if(direction == -1){
    direction = -1;
    x = x + direction*speed;
  } 
  
  if (x < 0){
    direction = 1
    speed++
    r = random(0,255);
    g = random(0,255);
    b = random(0,255);
  }
  
  
  
}