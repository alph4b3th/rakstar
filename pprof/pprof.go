package pprof

import (
	"net/http"
	_ "net/http/pprof"
)

func StartPPROF() {
	go func() {
		// Escute em um IP acessível externamente
		http.ListenAndServe("0.0.0.0:6060", nil)
	}()
}
