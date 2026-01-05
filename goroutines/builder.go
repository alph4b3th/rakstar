package goroutines

import (
	"log"
	"time"

	"github.com/panjf2000/ants"
)

type goroutine struct {
	runtimes int
}

func init() {
	var err error
	pool, err = ants.NewPool(defaultRuntimes, ants.WithOptions(ants.Options{
		PreAlloc:       false,
		Nonblocking:    false, //bloqueando pra testar
		ExpiryDuration: time.Duration(7) * time.Second,
		PanicHandler: func(i interface{}) {
			log.Println("[rakstar] a panic occurred in the server manager:", i)
		},
	}))

	if err != nil {
		panic(err)
	}
}

func Builder() *goroutine {
	g := new(goroutine)
	return g
}
