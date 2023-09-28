.PHONY: clean All

All:
	@echo "----------Building project:[ FINALfinal - Debug ]----------"
	@"$(MAKE)" -f  "FINALfinal.mk"
clean:
	@echo "----------Cleaning project:[ FINALfinal - Debug ]----------"
	@"$(MAKE)" -f  "FINALfinal.mk" clean
