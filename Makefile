.PHONY: clean All

All:
	@echo "----------Building project:[ F - Debug ]----------"
	@cd "F" && "$(MAKE)" -f  "F.mk"
clean:
	@echo "----------Cleaning project:[ F - Debug ]----------"
	@cd "F" && "$(MAKE)" -f  "F.mk" clean
