from pygame.locals import *
from random import randint
import pygame
import time

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

SNAKE_SIZE=25
APPLE_SIZE=20
BANANA_SIZE=20
CHERRY_SIZE=20
GRAPE_SIZE=20

class Fruit:
    x = 0
    y = 0

    def __init__(self,x,y):
        self.x = x * APPLE_SIZE
        self.y = y * APPLE_SIZE

    def draw(self, surface, image):
        surface.blit(image,(self.x, self.y))


class Player:
    x = [0]
    y = [0]
    direction = 0
    length = 3

    updateCountMax = 2
    updateCount = 0 

    def __init__(self, length):
        self.length = length
        for i in range(0,2000):
            self.x.append(-100)
            self.y.append(-100)

        # initial positions, no collision.
        self.x[1] = 1*SNAKE_SIZE
        self.x[2] = 2*SNAKE_SIZE

    def update(self):

        self.updateCount = self.updateCount + 1
        if self.updateCount > self.updateCountMax:

            # update previous positions
            # for (i = length -1; i>0; i--)
            for i in range(self.length-1,0,-1):
                self.x[i] = self.x[i-1]
                self.y[i] = self.y[i-1]

            # update position of head of snake
            if self.direction == 0:
                self.x[0] = self.x[0] + SNAKE_SIZE
            if self.direction == 1:
                self.x[0] = self.x[0] - SNAKE_SIZE
            if self.direction == 2:
                self.y[0] = self.y[0] - SNAKE_SIZE
            if self.direction == 3:
                self.y[0] = self.y[0] + SNAKE_SIZE

            if self.x[0] > SCREEN_WIDTH:
                self.x[0] = 0

            if self.y[0] > SCREEN_HEIGHT:
                self.y[0] = 0

            if self.x[0] < 0:
                self.x[0] = SCREEN_WIDTH - SNAKE_SIZE
            
            if self.y[0] < 0:
                self.y[0] = SCREEN_HEIGHT - SNAKE_SIZE

            self.updateCount = 0


    def moveRight(self):
        if self.direction != 1:
            self.direction = 0

    def moveLeft(self):
        if self.direction != 0:
            self.direction = 1

    def moveUp(self):
        if self.direction != 3:
            self.direction = 2

    def moveDown(self):
        if self.direction != 2:
            self.direction = 3

    def draw(self, surface, image):
        for i in range(0,self.length):
            surface.blit(image,(self.x[i],self.y[i]))

class Game: #checks if the snake and the apple collides, and snake collides with itself
    def isCollision(self,x1,y1,x2,y2, asize, bsize):
        if x1 + asize > x2 and x1 < x2 + bsize:
            if y1 + asize > y2 and y1 < y2 + bsize:
                return True
        return False

class App:

    windowWidth = SCREEN_WIDTH
    windowHeight = SCREEN_HEIGHT
    player = 0
    apple = 0

    def __init__(self):
        self._running = True
        self._display_surf = None
        self._image_surf = None
        self._apple_surf = None

        self._fruit_surf = list()
        self._fruit_number = 1
        self.game = Game()
        self.player = Player(5) #change the size of the player
        self.apple = Fruit(5,5)

    def on_init(self):
        pygame.init()
        self._display_surf = pygame.display.set_mode((self.windowWidth,self.windowHeight), pygame.HWSURFACE)

        pygame.display.set_caption('Pygame pythonspot.com example')
        self._running = True
        self._image_surf = pygame.image.load("snake.png").convert()
        self._apple_surf = pygame.image.load("apple.png").convert()

        
        self._fruit_surf.append(pygame.image.load("apple.png").convert())
        self._fruit_surf.append(pygame.image.load("banana.png").convert())
        self._fruit_surf.append(pygame.image.load("grape.png").convert())
        self._fruit_surf.append(pygame.image.load("cherry.png").convert())

    def on_event(self, event):
        if event.type == QUIT:
            self._running = False

    def on_loop(self):
        self.player.update()

        # does snake eat apple?
        for i in range(0,self.player.length):
            if self.game.isCollision(self.apple.x,self.apple.y,self.player.x[i], self.player.y[i],APPLE_SIZE, SNAKE_SIZE):
                self.apple.x = randint(2,SCREEN_WIDTH - APPLE_SIZE) #where the apples are placed on the screen
                self.apple.y = randint(2,SCREEN_HEIGHT - APPLE_SIZE)
                self.player.length = self.player.length + 1
                self._fruit_number = randint(0, len(self._fruit_surf)-1)


        # does snake collide with itself?
        for i in range(2,self.player.length):
            if self.game.isCollision(self.player.x[0],self.player.y[0],self.player.x[i], self.player.y[i],SNAKE_SIZE, SNAKE_SIZE):
                print("You lose! Collision: ")
                print("x[0] (" + str(self.player.x[0]) + "," + str(self.player.y[0]) + ")")
                print("x[" + str(i) + "] (" + str(self.player.x[i]) + "," + str(self.player.y[i]) + ")")
                exit(0)

        pass

    def on_render(self):
        self._display_surf.fill((0,0,0))
        self.player.draw(self._display_surf, self._image_surf)
        self.apple.draw(self._display_surf, self._fruit_surf[self._fruit_number])
        pygame.display.flip()

    def on_cleanup(self):
        pygame.quit()

    def on_execute(self):
        if self.on_init() == False:
            self._running = False

        clock = pygame.time.Clock()
        while( self._running ):
            pygame.event.pump()
            keys = pygame.key.get_pressed()

            if (keys[K_RIGHT]):
                self.player.moveRight()

            if (keys[K_LEFT]):
                self.player.moveLeft()

            if (keys[K_UP]):
                self.player.moveUp()

            if (keys[K_DOWN]):
                self.player.moveDown()

            if (keys[K_ESCAPE]):
                self._running = False

            self.on_loop()
            self.on_render()

            clock.tick(50)
        self.on_cleanup()

if __name__ == "__main__" :
    print("Hello")
    theApp = App()
    theApp.on_execute()