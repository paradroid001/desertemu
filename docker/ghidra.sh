docker run --init -it --rm \
            --name ghidra \
            --cpus 2 \
            --memory 4g \
            -e MAXMEM=4G \
            -e DISPLAY=$DISPLAY \
            -h $HOSTNAME \
            -v /tmp/.X11-unix:/tmp/.X11-unix \
            -v /tmp/samples:/samples \
            -v /tmp/root:/root \
            -v $HOME/.Xauthority:/root/.Xauthority \
            -v ${PWD}/test/:/test \
            blacktop/ghidra