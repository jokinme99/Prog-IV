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
  UNIQUE INDEX `id_UNIQUE` (`id_restaurante` ASC)  ,
  UNIQUE INDEX `nombre_UNIQUE` (`nombre` ASC)  ,
  UNIQUE INDEX `telefono_UNIQUE` (`telefono` ASC)  )
ENGINE = InnoDB;
insert into restaurante values(1, "Goiko", "Don Diego López Haroko Kale Nagusia, 68, 48011 Bilbo, Bizkaia", "Hamburguesa", 123456789, 30);
insert into restaurante values(2, "Telepizza", "Pz. de la Casilla, 2, 48012 Bilbao, BI", "Pizza", 123456788, 15);
insert into restaurante values(3, "Krunch", "Leizaola Lehendakariaren Kalea, 2, 48015 Bilbo, Bizkaia", "Carne", 123456789, 25);
insert into restaurante values(4, "Charli", "Don Diego López Haroko Kale Nagusia, 68, 48011 Bilbo, Bizkaia", "kebab", 123456789, 30);
insert into restaurante values(5, "El bar de jon", "Pz. de la Casilla, 2, 48012 Bilbao, BI", "Pizza", 123456788, 15);
insert into restaurante values(6, "In&out", "Leizaola Lehendakariaren Kalea, 2, 48015 Bilbo, Bizkaia", "Carne", 123456789, 25);insert into restaurante values(1, "Goiko", "Don Diego López Haroko Kale Nagusia, 68, 48011 Bilbo, Bizkaia", "Hamburguesa", 123456789, 30);
insert into restaurante values(7, "pepe", "Pz. de la Casilla, 2, 48012 Bilbao, BI", "Pizza", 123456788, 15);
insert into restaurante values(8, "marianoren erxea", "Leizaola Lehendakariaren Kalea, 2, 48015 Bilbo, Bizkaia", "Carne", 123456789, 25);
-- -----------------------------------------------------
-- Table `e-restaurants`.`menu`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`menu` (
  `id_menu` INT NOT NULL AUTO_INCREMENT,
  `precio` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`id_menu`),
  UNIQUE INDEX `id_menu_UNIQUE` (`id_menu` ASC)  )
ENGINE = InnoDB;
insert into menu values(1, "5.5");
insert into menu values(2, "4");
insert into menu values(3, "4.5");
insert into menu values(4, "8.5");
insert into menu values(5, "9.5");
insert into menu values(6, "5.5");
insert into menu values(7, "12");


-- -----------------------------------------------------
-- Table `e-restaurants`.`producto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`producto` (
  `id_producto` INT NOT NULL AUTO_INCREMENT,
  `nombre_producto` VARCHAR(45) NOT NULL,
  `descripcion` VARCHAR(45) NOT NULL,
  `precio` FLOAT NOT NULL,
  PRIMARY KEY (`id_producto`),
  UNIQUE INDEX `id_producto_UNIQUE` (`id_producto` ASC)  ,
  UNIQUE INDEX `nombre_producto_UNIQUE` (`nombre_producto` ASC)  ,
  UNIQUE INDEX `descripcion_UNIQUE` (`descripcion` ASC)  )
ENGINE = InnoDB;
insert into producto values(1, "Coca-cola", "Bebida refrescante", 2);
insert into producto values(2, "Kas", "Bebida refrescante", 2);
insert into producto values(3, "Hamburguesa", "Hamburguesa con todo tipo ingredientes de la casa", 5.5);
insert into producto values(4, "Pizza de jamon y queso", "La tradicional pizza de jamon y queso con nuestro toque especial", 7);
insert into producto values(5, "Pan", "Bebida refrescante", 2);
insert into producto values(6, "Ensalada", "Bebida refrescante", 2);
insert into producto values(7, "Merluza", "Hamburguesa con todo tipo ingredientes de la casa", 5.5);
insert into producto values(8, "Alubias rojas", "La tradicional pizza de jamon y queso con nuestro toque especial", 7);


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
  UNIQUE INDEX `id_Trabajador_UNIQUE` (`id_Trabajador` ASC)  ,
  UNIQUE INDEX `DNI_UNIQUE` (`DNI` ASC)  ,
  INDEX `fk_Trabajador_restaurante1_idx` (`restaurante_id_restaurante` ASC)  ,
  CONSTRAINT `fk_Trabajador_restaurante1`
    FOREIGN KEY (`restaurante_id_restaurante`)
    REFERENCES `e-restaurants`.`restaurante` (`id_restaurante`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

insert into trabajador values(1, "Jokin", 1700, "12354678D", 1);
insert into trabajador values(2, "Mikel", 1650, "12354321J", 1);
insert into trabajador values(3, "Aitor", 1557.60, "854467825M", 1);
insert into trabajador values(4, "Borja", 1500, "95448748D", 2);
insert into trabajador values(5, "sergio", 1700, "12354678D", 2);
insert into trabajador values(6, "jon", 1650, "12354321J", 2);
insert into trabajador values(7, "iker", 1557.60, "854467825M", 3);
insert into trabajador values(8, "asier", 1500, "95448748D", 3);
insert into trabajador values(9, "luka", 1700, "12354678D", 3);
insert into trabajador values(10, "maider", 1650, "12354321J", 4);
insert into trabajador values(11, "nerea", 1557.60, "854467825M", 4);
insert into trabajador values(12, "leire", 1500, "95448748D", 4);
insert into trabajador values(13, "ane", 1700, "12354678D", 5);
insert into trabajador values(14, "ander", 1650, "12354321J", 5);
insert into trabajador values(15, "koldo", 1557.60, "854467825M", 5);
insert into trabajador values(16, "maite", 1500, "95448748D", 6);
insert into trabajador values(17, "andrea", 1700, "12354678D", 6);
insert into trabajador values(18, "sara", 1650, "12354321J", 6);
insert into trabajador values(19, "kerman", 1557.60, "854467825M", 7);
insert into trabajador values(20, "josu", 1500, "95448748D", 7);
insert into trabajador values(21, "xabier", 1700, "12354678D", 7);
insert into trabajador values(22, "lander", 1650, "12354321J", 8);
insert into trabajador values(23, "patxi", 1557.60, "854467825M", 8);
insert into trabajador values(24, "peio", 1500, "95448748D", 8);
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
  UNIQUE INDEX `idusuario_UNIQUE` (`idusuario` ASC)  ,
  UNIQUE INDEX `DNI_UNIQUE` (`DNI` ASC)  )
ENGINE = InnoDB;

insert into usuario values(1, "Iker", "Lopez", "65436556G", 50.47, "admin");
insert into usuario values(2, "Ane", "Gutierrez", "52348315X", 20, "cliente");
insert into usuario values(3, "Ana", "Merino", "98732154C", 30.37, "cliente");
insert into usuario values(4, "Marcos", "Gonzalez", "24587913K", 9, "cliente");
-- -----------------------------------------------------
-- Table `e-restaurants`.`menu_tiene_productos`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`menu_tiene_productos` (
  `menu_id_menu` INT NOT NULL,
  `producto_id_producto` INT NOT NULL,
  PRIMARY KEY (`menu_id_menu`, `producto_id_producto`),
  INDEX `fk_menu_has_producto_producto1_idx` (`producto_id_producto` ASC)  ,
  INDEX `fk_menu_has_producto_menu_idx` (`menu_id_menu` ASC)  ,
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
insert into menu_tiene_productos values(1, 1);
insert into menu_tiene_productos values(1, 2);
insert into menu_tiene_productos values(1, 3);
insert into menu_tiene_productos values(2, 4);
insert into menu_tiene_productos values(2, 5);
insert into menu_tiene_productos values(2, 6);
insert into menu_tiene_productos values(3, 7);
insert into menu_tiene_productos values(3, 8);
insert into menu_tiene_productos values(3, 1);
insert into menu_tiene_productos values(4, 2);
insert into menu_tiene_productos values(4, 3);
insert into menu_tiene_productos values(4, 4);
insert into menu_tiene_productos values(5, 5);
insert into menu_tiene_productos values(5, 6);
insert into menu_tiene_productos values(5, 7);
insert into menu_tiene_productos values(6, 8);
insert into menu_tiene_productos values(6, 1);
insert into menu_tiene_productos values(6, 2);
insert into menu_tiene_productos values(7, 3);
insert into menu_tiene_productos values(7, 4);
insert into menu_tiene_productos values(7, 5);


-- -----------------------------------------------------
-- Table `e-restaurants`.`restaurante_tiene_menu`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `e-restaurants`.`restaurante_tiene_menu` (
  `restaurante_id_restaurante` INT NOT NULL,
  `menu_id_menu` INT NOT NULL,
  PRIMARY KEY (`restaurante_id_restaurante`, `menu_id_menu`),
  INDEX `fk_restaurante_has_menu_menu1_idx` (`menu_id_menu` ASC)  ,
  INDEX `fk_restaurante_has_menu_restaurante1_idx` (`restaurante_id_restaurante` ASC)  ,
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
insert into restaurante_tiene_menu values(1, 1);
insert into restaurante_tiene_menu values(1, 2);
insert into restaurante_tiene_menu values(1, 3);
insert into restaurante_tiene_menu values(2, 4);
insert into restaurante_tiene_menu values(2, 5);
insert into restaurante_tiene_menu values(2, 6);
insert into restaurante_tiene_menu values(3, 7);
insert into restaurante_tiene_menu values(3, 1);
insert into restaurante_tiene_menu values(3, 2);
insert into restaurante_tiene_menu values(4, 3);
insert into restaurante_tiene_menu values(4, 4);
insert into restaurante_tiene_menu values(4, 5);
insert into restaurante_tiene_menu values(5, 6);
insert into restaurante_tiene_menu values(5, 7);
insert into restaurante_tiene_menu values(5, 1);
insert into restaurante_tiene_menu values(6, 2);
insert into restaurante_tiene_menu values(6, 3);
insert into restaurante_tiene_menu values(6, 4);
insert into restaurante_tiene_menu values(7, 5);
insert into restaurante_tiene_menu values(7, 6);
insert into restaurante_tiene_menu values(7, 7);
insert into restaurante_tiene_menu values(8, 1);
insert into restaurante_tiene_menu values(8, 2);
insert into restaurante_tiene_menu values(8, 3);

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
