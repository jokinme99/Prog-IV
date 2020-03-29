-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema e-restaurants
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema e-restaurants
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `e-restaurants` DEFAULT CHARACTER SET utf8 ;
USE `e-restaurants` ;

-- -----------------------------------------------------
-- Table `e-restaurants`.`restaurante`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`restaurante` (
  `id_restaurante` INT NOT NULL,
  `nombre` VARCHAR(45) NOT NULL,
  `direccion` VARCHAR(45) NOT NULL,
  `tipoComida` VARCHAR(45) NOT NULL,
  `telefono` INT(9) NOT NULL,
  `num_mesas` INT(50) NULL,
  PRIMARY KEY (`id_restaurante`),
  UNIQUE INDEX `id_UNIQUE` (`id_restaurante` ASC) VISIBLE,
  UNIQUE INDEX `nombre_UNIQUE` (`nombre` ASC) VISIBLE,
  UNIQUE INDEX `telefono_UNIQUE` (`telefono` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `e-restaurants`.`menu`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`menu` (
  `id_menu` INT NOT NULL AUTO_INCREMENT,
  `precio` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_menu`),
  UNIQUE INDEX `id_menu_UNIQUE` (`id_menu` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `e-restaurants`.`producto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`producto` (
  `id_producto` INT NOT NULL AUTO_INCREMENT,
  `nombre_producto` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(45) NOT NULL,
  `precio` FLOAT NOT NULL,
  PRIMARY KEY (`id_producto`),
  UNIQUE INDEX `id_producto_UNIQUE` (`id_producto` ASC) VISIBLE,
  UNIQUE INDEX `nombre_producto_UNIQUE` (`nombre_producto` ASC) VISIBLE,
  UNIQUE INDEX `descripcion_UNIQUE` (`descripcion` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `e-restaurants`.`Trabajador`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`Trabajador` (
  `id_Trabajador` INT NOT NULL AUTO_INCREMENT,
  `nombre_trabajador` VARCHAR(45) NOT NULL,
  `sueldo` FLOAT NOT NULL,
  `DNI` VARCHAR(9) NOT NULL,
  `restaurante_id_restaurante` INT NOT NULL,
  PRIMARY KEY (`id_Trabajador`),
  UNIQUE INDEX `id_Trabajador_UNIQUE` (`id_Trabajador` ASC) VISIBLE,
  UNIQUE INDEX `DNI_UNIQUE` (`DNI` ASC) VISIBLE,
  INDEX `fk_Trabajador_restaurante1_idx` (`restaurante_id_restaurante` ASC) VISIBLE,
  CONSTRAINT `fk_Trabajador_restaurante1`
    FOREIGN KEY (`restaurante_id_restaurante`)
    REFERENCES `e-restaurants`.`restaurante` (`id_restaurante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `e-restaurants`.`usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`usuario` (
  `idusuario` INT NOT NULL AUTO_INCREMENT,
  `nombre` VARCHAR(45) NOT NULL,
  `apellidos` VARCHAR(45) NOT NULL,
  `DNI` VARCHAR(9) NOT NULL,
  `saldo` FLOAT NOT NULL,
  `tipo` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idusuario`),
  UNIQUE INDEX `idusuario_UNIQUE` (`idusuario` ASC) VISIBLE,
  UNIQUE INDEX `DNI_UNIQUE` (`DNI` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `e-restaurants`.`menu_tiene_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`menu_tiene_productos` (
  `menu_id_menu` INT NOT NULL,
  `producto_id_producto` INT NOT NULL,
  PRIMARY KEY (`menu_id_menu`, `producto_id_producto`),
  INDEX `fk_menu_has_producto_producto1_idx` (`producto_id_producto` ASC) VISIBLE,
  INDEX `fk_menu_has_producto_menu_idx` (`menu_id_menu` ASC) VISIBLE,
  CONSTRAINT `fk_menu_has_producto_menu`
    FOREIGN KEY (`menu_id_menu`)
    REFERENCES `e-restaurants`.`menu` (`id_menu`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_menu_has_producto_producto1`
    FOREIGN KEY (`producto_id_producto`)
    REFERENCES `e-restaurants`.`producto` (`id_producto`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `e-restaurants`.`restaurante_tiene_menu`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`restaurante_tiene_menu` (
  `restaurante_id_restaurante` INT NOT NULL,
  `menu_id_menu` INT NOT NULL,
  PRIMARY KEY (`restaurante_id_restaurante`, `menu_id_menu`),
  INDEX `fk_restaurante_has_menu_menu1_idx` (`menu_id_menu` ASC) VISIBLE,
  INDEX `fk_restaurante_has_menu_restaurante1_idx` (`restaurante_id_restaurante` ASC) VISIBLE,
  CONSTRAINT `fk_restaurante_has_menu_restaurante1`
    FOREIGN KEY (`restaurante_id_restaurante`)
    REFERENCES `e-restaurants`.`restaurante` (`id_restaurante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_restaurante_has_menu_menu1`
    FOREIGN KEY (`menu_id_menu`)
    REFERENCES `e-restaurants`.`menu` (`id_menu`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
