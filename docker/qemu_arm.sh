docker run -it --rm \
           --name qemu \
           -e "BOOT=http://example.com/image.iso" \
           -p 8006:8006 \
           --device=/dev/kvm \
           --cap-add NET_ADMIN \
           qemux/qemu-arm
