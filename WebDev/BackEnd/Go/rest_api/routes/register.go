package routes

import (
	"fmt"
	"net/http"
	"strconv"

	"example.com/restapi/models"
	"github.com/gin-gonic/gin"
)

func registerForEvent(context *gin.Context) {
	userId := context.GetInt64("userId")
	eventId, err := strconv.ParseInt(context.Param("id"), 10, 64)
	if err != nil {
		context.JSON(http.StatusBadRequest, gin.H{"message": fmt.Sprint(err)})
		return
	}

	event, err := models.GetEventByID(eventId)
	if err != nil {
		context.JSON(http.StatusInternalServerError, gin.H{"message": fmt.Sprint(err)})
		return
	}

	err = event.RegisterEventByID(userId)
	if err != nil {
		context.JSON(http.StatusInternalServerError, gin.H{"message": fmt.Sprint(err)})
		return
	}

	context.JSON(http.StatusCreated, gin.H{"message": fmt.Sprintf("Registered Event %v by User %v", eventId, userId)})
}

func cancelEventRegistration(context *gin.Context) {

}
