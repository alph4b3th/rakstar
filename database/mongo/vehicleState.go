package mongodb

import (
	"context"
	"runtime"

	"github.com/alph4b3th/rakstar/goroutines"
	"go.mongodb.org/mongo-driver/mongo/options"
)

func (mb *MongoBase) CreateVehicleStateWithWorkers(vehicle interface{}) {
	goroutines.Builder().Submit(func() {
		runtime.Gosched()
		mb.collection.InsertOne(context.TODO(), vehicle)
	})
}

func (mb *MongoBase) GetVehicleState(vehicle, filter interface{}, opts ...*options.FindOneOptions) error {
	return mb.collection.FindOne(context.TODO(), filter, opts...).Decode(vehicle)
}
