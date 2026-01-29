package routes

import (
	middlewares "example.com/restapi/middle-wares"
	"github.com/gin-gonic/gin"
)

func RegisterRoutes(server *gin.Engine) {
	server.GET("/events", getEvents)
	server.GET("/events/:id", getSingleEvent)

	authenticated := server.Group("/events")
	authenticated.Use(middlewares.Authenticate)
	authenticated.POST("", createEvent)
	authenticated.PUT("/:id", updateEvent)
	authenticated.DELETE("/:id", deleteEvent)
	authenticated.POST("/:id/register", registerForEvent)
	authenticated.DELETE("/:id/register", cancelEventRegistration)

	server.POST("/signup", signup)
	server.POST("/login", login)
}
